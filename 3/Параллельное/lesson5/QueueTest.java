package lesson5;

import java.util.concurrent.ArrayBlockingQueue;

public class QueueTest {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		final ArrayBlockingQueue<String> q = new ArrayBlockingQueue<>(10);
		
		q.put("test");
		System.err.println("Got: "+q.take());
		System.err.println("Poll: "+q.poll());
		
		
	}

}
