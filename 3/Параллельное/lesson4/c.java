package lesson4;

import java.util.concurrent.Semaphore;

public class c{
	public static void main(String[] args) {
		final Semaphore	sema = new Semaphore(3);
		
		for (int index = 0; index < 10; index++) {
			final Thread t = new Thread(()->{
					try{sema.acquire(); // synchronized(..) {
					} catch (InterruptedException e1) {
					}
					
					System.err.println("Thread:"
					+Thread.currentThread().getName());
					try{Thread.sleep((long)(1000+200*Math.random()));
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					sema.release();	// }
				});
			t.start();
		}
	}
}
