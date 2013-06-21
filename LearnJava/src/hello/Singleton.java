package hello;

public enum Singleton {
	INSTANCE;
	
	Singleton() {}
	
	public static void main(String [] args) {
		System.out.println("This is enum class " + Singleton.INSTANCE) ;
	}

}
