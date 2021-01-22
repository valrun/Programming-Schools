package lesson3;

import java.util.concurrent.Exchanger;
import java.util.concurrent.Semaphore;

public class PerformanceOptimization {

	public static void main(String[] args) throws InterruptedException {
		final Exchanger<Result> ex = new Exchanger<>();
		
		for (int index = 0; index < 3; index++) {
			final Thread t = new Thread(()-> {
				for (int loop = 0; loop < 100; loop++) {
					final Result	result = new Result(
									Thread.currentThread().getName());
					
					try{System.err.println("Source="+result.result);
						synchronized(ex) {
							ex.exchange(result);
						}
						Thread.sleep(1000);
						result.completed.acquire();
						System.err.println("Result="+result.result);
					} catch (InterruptedException e) {
						break;
					}
				}
			});
			t.start();
		}
		
		for (int index = 0; index < 300; index++) {
			final Result source = ex.exchange(null);
			
			Thread.sleep(500);
			source.result = source.result.toUpperCase();
			source.completed.release();
		}
	}

	static class Result {
		volatile String	result;
		final Semaphore completed = new Semaphore(0);
		
		Result(String source) {
			result = source;
		}
	}
}
