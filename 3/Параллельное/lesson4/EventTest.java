package lesson4;

import java.util.concurrent.Semaphore;

public class EventTest {
	public static int x;
	public static int y;
	

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		final Semaphore tr = new Semaphore(0);
		final Semaphore rcv = new Semaphore(0);
		
		final Thread transmitter = new Thread(()-> {
			x = (int) (1000 * Math.random());
			System.err.println("Place x = " + x + " " +
						Thread.currentThread().getName());
			/*
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
			}
			*/
			tr.release();
			try {rcv.acquire();
			} catch (InterruptedException e) {
				System.err.println("Ready y = " + y + " " +
						Thread.currentThread().getName());
			}
				
			
		}) ;
		transmitter.start();
		
		tr.acquire();
		System.err.println("rec x = " + x);
		y = x * x;
		System.err.println("prog y = " + y);
		rcv.release();
		

	}

}
