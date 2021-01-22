package lesson4;

import java.util.concurrent.Exchanger;
import java.util.concurrent.Semaphore;

import javax.sound.midi.Transmitter;

public class ExchangerAndEventTest {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		final Exchanger<Request> ex = new Exchanger<>();
//		final Exchanger<Integer> exReady = new Exchanger<>();
		
		for (int count = 0; count < 3; count++) {
			Thread transmitter = new Thread(()->{
				for (int i = 0; i < 10; i++) {
					int send = (int) (1000 * Math.random());
					System.err.println("Send: "+send+
							" "+Thread.currentThread().getName());
					Request rq = null;
					synchronized(ex) {
						try{ex.exchange(rq = new Request(send));
						} catch (InterruptedException e) {
						}
					}
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e1) {
					}
					try{rq.completed.acquire();
					System.err.println("Ready: "+rq.value
					+ 
					" "+Thread.currentThread().getName());
					} catch (InterruptedException e) {
					}
				}
			});
			transmitter.start();
		}

		for (int j = 0; j < 30; j++) {
			final Request rcv = ex.exchange(null);
			System.err.println("REceived: "+rcv.value);
			Thread.sleep(500);
			rcv.value *= rcv.value; 
			rcv.completed.release();
		}
		
	}

	static class Request {
		volatile int	value;
		final Semaphore	completed = new Semaphore(0);
		
		Request(int value){
			this.value = value;
		}
	}
}
