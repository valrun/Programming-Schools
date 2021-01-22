package lesson5;

public class DijkstraTask {

	public static void main(String[] args) {
		final Object stick1 = new Object(), stick2 = new Object(),
				     stick3 = new Object(), stick4 = new Object(),
				     stick5 = new Object();
		final Thread phil1 = new Thread(()->loop(stick1,stick2));
		final Thread phil2 = new Thread(()->loop(stick2,stick3));
		final Thread phil3 = new Thread(()->loop(stick3,stick4));
		final Thread phil4 = new Thread(()->loop(stick4,stick5));
		final Thread phil5 = new Thread(()->loop(stick1,stick5));
		
		phil1.start();
		phil2.start();
		phil3.start();
		phil4.start();
		phil5.start();
	}

	
	static void loop(final Object stick1, final Object stick2) {
		try {
			for (;;) {
				synchronized(stick1) {
					synchronized(stick2) {
						eating();
					}
				}
				thinking();
			}
		} catch (InterruptedException exc) {	
		}
	}
	
	static void eating() throws InterruptedException {
		System.err.println(Thread.currentThread().getName()+" eating");
//		Thread.sleep(1000);
	}

	static void thinking() throws InterruptedException {
		System.err.println(Thread.currentThread().getName()+" thinking");
//		Thread.sleep(5000);
	}
}
