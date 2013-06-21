package currency;

public class TestClass {
	public static void main(String [] args) {
		MyRunnable r = new MyRunnable();
		Thread t = new Thread(r);
		t.setName("R2");
		t.start();
		Thread t2 = new Thread(r);
		t2.start();
		//t.run(); // Legal, but does not start a new thread
		
	}
}
