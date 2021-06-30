package lesson6;

import java.io.File;
import java.util.concurrent.Semaphore;
import java.util.Arrays;
import java.util.concurrent.ArrayBlockingQueue;

public class TestDispatcher {

	public static void main(String[] args) throws InterruptedException {
		final ArrayBlockingQueue<Request> queue = new ArrayBlockingQueue<>(10);
		
		
		for (int i = 0; i < 3; i++) {
			final Thread t = new Thread(()-> {
				try{
					double sum = 0.0;
					for (int j = 0; j < 3; j++) {
						final Request rq1 = new Request(j + (int)(Math.random() * 10));
						
						queue.put(rq1);
						rq1.waitCompletion();
						
						if (!rq1.getFile().exists()) {
							j--;
						} else {
							sum ++;
						}
						System.err.println(rq1.getFile().getName());
					}
					System.err.println(" " + sum);
					
				} catch (InterruptedException exc) {
				}
				
			});
			t.start();
		}
		processRequests(queue);

	}
	
	static void processRequests(final ArrayBlockingQueue<Request> queue) throws InterruptedException {

		
		File f = new File("G:\\");
		final File sticks[] = f.listFiles();
/*		
		for (int i = 0; i < sticks.length; i++) {
			System.err.println(sticks[i].getName());
		}
*/		
		final boolean[] lock = new boolean[sticks.length];
		
		for (;;) {
			final Request rq = queue.take();

					if (lock[rq.getInt()] == false) {
						lock[rq.getInt()] = true;
						rq.takeFile(sticks[rq.getInt()]);
						rq.markCompleted();
					}
					else {
						rq.markCompleted();
					}
		}
	}
	static class Request {
		private final Semaphore sema = new Semaphore(0);
		private File f;
		private final int r;

		
		public Request(final int r) {
			super();
			this.r= r;
		}

		int getInt() {
			return r;
		}
		
		public void takeFile(File f) {
			this.f = f;
		}
		
		File getFile() {
			return f;
		}
		
		void waitCompletion() throws InterruptedException {
			sema.acquire();
		}
		
		void markCompleted() {
			sema.release();
		}
/*
		@Override
		public String toString() {
			return "Request [rt=" + rt + ", resourceList=" + Arrays.toString(resourceList) + "]";
		}
*/
	}

}
