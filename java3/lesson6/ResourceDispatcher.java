package calc;

import java.util.Arrays;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Semaphore;

public class ResourceDispatcher {
	static final int PHILOSOPHES_AMONT = 5;
	

	public static void main(String[] args) throws InterruptedException {
		final ArrayBlockingQueue<Request> queue = new ArrayBlockingQueue<>(10);

		for (int index = 0; index < PHILOSOPHES_AMONT; index++) {
			final int firstStick = index % PHILOSOPHES_AMONT, secondStick = (index + 1) % PHILOSOPHES_AMONT; 
			
			final Thread t = new Thread(()->{
				try{
					for (;;) {
						final Request rq1 = new Request(Request.RequestType.GetSticks,firstStick,secondStick); 
						
						queue.put(rq1);
						rq1.waitCompletion();
						eating();
						
						final Request rq2 = new Request(Request.RequestType.ReleaseSticks,firstStick,secondStick); 
						
						queue.put(rq2);
						rq2.waitCompletion();
						thinking();
					}
				} catch (InterruptedException exc) {
				}
			});
			t.setName("Scientist "+index);
			t.start();
		}
		processRequests(queue);
	}

	static void eating() throws InterruptedException {
		System.err.println(Thread.currentThread().getName()+" eating...");
//		Thread.sleep(2000);
	}

	static void thinking() throws InterruptedException {
		System.err.println(Thread.currentThread().getName()+" thinking...");
//		Thread.sleep(2000);
	}
	
	
	static void processRequests(final ArrayBlockingQueue<Request> queue) throws InterruptedException {
		final boolean[] sticks = new boolean[PHILOSOPHES_AMONT];
		final Request[] awaited = new Request[PHILOSOPHES_AMONT];
		int roundRobinStart = 0;
		
		for (;;) {
			final Request rq = queue.take();

//			System.err.println("Processing: "+rq);
			switch (rq.getRequestType()) {
				case GetSticks :
					if (sticks[rq.getResourceList()[0]] == false && sticks[rq.getResourceList()[1]] == false) {
						sticks[rq.getResourceList()[0]] = true;
						sticks[rq.getResourceList()[1]] = true;
						rq.markCompleted();
					}
					else {
						awaited[rq.getResourceList()[0]] = rq;
					}
					break;
				case ReleaseSticks :
					sticks[rq.getResourceList()[0]] = false;
					sticks[rq.getResourceList()[1]] = false;
seek:				for (int index = 0; index < sticks.length; index++) {
						int currentIndex = (index + roundRobinStart) % PHILOSOPHES_AMONT;
						Request temp = awaited[currentIndex]; 
						
						if (temp != null && sticks[temp.getResourceList()[0]] == false && sticks[temp.getResourceList()[1]] == false) {
							awaited[currentIndex] = null;
							temp.markCompleted();
							roundRobinStart++;
							continue seek;
						}
					}
					rq.markCompleted();
					break;
			}
		}
	}
	
	static class Request {
		private final Semaphore sema = new Semaphore(0);
		private final RequestType rt;
		private final int[] resourceList;
		
		enum RequestType {
			GetSticks, ReleaseSticks
		}
		
		public Request(final RequestType rt, final int leftStick, final int rightStick) {
			super();
			this.rt = rt;
			this.resourceList = new int[]{leftStick,rightStick};
		}

		RequestType getRequestType() {
			return rt;
		}
		
		int[] getResourceList() {
			return resourceList;
		}
		
		void waitCompletion() throws InterruptedException {
			sema.acquire();
		}
		
		void markCompleted() {
			sema.release();
		}

		@Override
		public String toString() {
			return "Request [rt=" + rt + ", resourceList=" + Arrays.toString(resourceList) + "]";
		}
	}
}
