package currency;

public class MyThread extends Thread {
	public void run() {
		System.out.println("Thread Hello world..");
	}
	
	public static void main(String [] args) {
		Thread k = new Thread(new MyThread());
		k.start();
		
	}
}
