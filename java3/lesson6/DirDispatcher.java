package lesson6;

import java.io.File;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Semaphore;

public class DirDispatcher implements AutoCloseable {

	public static void main(String[] args) throws Exception {
		try(final DirDispatcher dd = new DirDispatcher()) {
			// try(final ResourceLocker rl = dd.lock(...,...,...,)) {
			// do something
			// }			
		}
	}

	private final Set<File> lockedNow = new HashSet<>();
	private final Thread dispatcherThread;
	private final ArrayBlockingQueue<Request> queue = new ArrayBlockingQueue<>(10); 
	private List<Request> failed = new ArrayList<>();
	
	public DirDispatcher() {
		dispatcherThread = new Thread(()-> {dispatch();});
		dispatcherThread.start();
	}
	
	@Override
	public void close() throws Exception {
		dispatcherThread.interrupt();
	}

	
	public ResourceLocker lock(File f1, File f2, File f3) throws InterruptedException {
		final Request rq = new Request(true,f1, f2, f3); 
		
		queue.put(rq);
		rq.waitCompletion();
		return new ResourceLockerImpl(f1, f2, f3);
	}
	
	private void dispatch() {
		for (;;) {
			try{final Request rq = queue.take();
			
				if (rq.lock) {
					if (tryLock(rq.f1,rq.f2,rq.f3)) {
						rq.completed();
					}
					else {
						failed.add(rq);
					}
				}
				else {
					lockedNow.remove(rq.f1);
					lockedNow.remove(rq.f2);
					lockedNow.remove(rq.f3);
					
					for (int index = failed.size()-1; index >= 0; index--) {
						final Request testRq = failed.get(index);
						
						if (tryLock(testRq.f1,testRq.f2,testRq.f3)) {
							failed.remove(index).completed();
						}
					}
				}
			} catch (InterruptedException e) {
				break;
			}
		}
	}
	
	private boolean tryLock(final File f1, final File f2, final File f3) {
		if (!lockedNow.contains(f1) && !lockedNow.contains(f2) && !lockedNow.contains(f3)) {
			lockedNow.add(f1);
			lockedNow.add(f2);
			lockedNow.add(f3);
			return true;
		}
		else {
			return false;
		}
	}

	private class ResourceLockerImpl implements ResourceLocker {
		final File f1, f2, f3;
		
		private ResourceLockerImpl(File f1, File f2, File f3) {
			this.f1 = f1;
			this.f2 = f2;
			this.f3 = f3;
		}

		@Override
		public void close() {
			final Request rq = new Request(false,f1, f2, f3); 
			
			try{queue.put(rq);
				rq.waitCompletion();
			} catch (InterruptedException e) {
			}
		}
	}

	private static class Request {
		final boolean lock;
		final File f1, f2, f3;
		final Semaphore sema = new Semaphore(0);
		
		private Request(boolean lock, File f1, File f2, File f3) {
			super();
			this.lock = lock;
			this.f1 = f1;
			this.f2 = f2;
			this.f3 = f3;
		}

		public void completed() {
			sema.release();
		}
		
		public void waitCompletion() throws InterruptedException {
			sema.acquire();
		}
	}
}
