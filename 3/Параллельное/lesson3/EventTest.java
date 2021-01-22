import java.util.concurrent.Semaphore;

public class EventTest {
	static volatile int x;

	public static void main(String[] args) throws InterruptedException {
		final Semaphore	sema = new Semaphore(0);
		
		final Thread	t = new Thread(()-> {
			for (int index = 0; index < 10; index++) {
				try{Thread.sleep(1000);
				} catch (InterruptedException e) {
				}
				x = (int) (100*Math.random());
				sema.release();
			}
		});
		t.start();
		for (int index = 0; index < 10; index++) {
			sema.acquire();
			System.err.println(x);
		}
	}

}
