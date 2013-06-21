package hello;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class SerializeTest implements Serializable {
	private String name;
	private String age;
	SerializeTest(String name, String age) {
		this.name = name;
		this.age = age;
	}
	
	public String getName() {
		return this.name;
	}
	
	public static void main(String [] args) {
		SerializeTest ss = new SerializeTest("QQ", "100");
		try {
			FileOutputStream fo = new FileOutputStream ("test.txt");
			ObjectOutputStream out = new ObjectOutputStream(fo);
			out.writeObject(ss);
			out.close();
			fo.close();
		} catch (IOException i) {
			i.printStackTrace();
		}
		
		try {
			FileInputStream fi = new FileInputStream ("test.txt");
			ObjectInputStream inn = new ObjectInputStream(fi);
			SerializeTest e = (SerializeTest) inn.readObject();
			System.out.println("After Des : " + e.getName());
		} catch (IOException i) {
			i.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
