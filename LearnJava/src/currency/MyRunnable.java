package currency;

public class MyRunnable implements Runnable {

	@Override
	public void run() {
		int k  =0;
		k++;
		System.out.println("Thread " + Thread.currentThread().getName()+ " "+ k);
		try {
			Thread.sleep(5*1000);
		} catch (InterruptedException ex) { 
			//Do nothing
		}
		System.out.println("Finished sleeping");
		
	}

}
