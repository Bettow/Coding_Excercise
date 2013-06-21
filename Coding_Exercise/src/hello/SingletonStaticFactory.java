package hello;

import java.io.ObjectStreamException;

//public class SingletonStaticFactory implements Serializable { 
public class SingletonStaticFactory {
	private static final SingletonStaticFactory INSTANCE = new SingletonStaticFactory();
	private SingletonStaticFactory() {}
	public static SingletonStaticFactory getInstance() {
		return INSTANCE;
	}
	private Object readResolve() throws ObjectStreamException {
		  // instead of the object we're on, 
		  // return the class variable INSTANCE
		return INSTANCE;
	}

}
