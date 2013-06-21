package mit;

import java.util.ArrayList;
import java.util.Arrays;

import structure.BstTreeNode;
import structure.TreeNode;

public class SerializeBst {
	public BstTreeNode deserializeTree(ArrayList<String> s) {
		if (s.size() == 0 ) return null;
		String c = s.get(0);
		if (c == "#") 
			return null;
		
		int val = Integer.parseInt(c);
		BstTreeNode root = new BstTreeNode(val);
		s.remove(0);
		if (!s.isEmpty())
			root.left = deserializeTree(s);
		if (!s.isEmpty())
			s.remove(0);
		if (!s.isEmpty())
			root.right = deserializeTree(s);
		
		return root;		
	}
	
	public ArrayList<String> serializeTree(BstTreeNode root) {
		ArrayList<String> ret = new ArrayList<String>();
		if (root == null) {
			ret.add("#");
			return ret;
		}
		
		ret.add(Integer.toString(root.val));
		ArrayList<String> r = serializeTree(root.left);
		ret.addAll(r);
		r = serializeTree(root.right);
		ret.addAll(r);
		return ret;
	}

	public static void main(String [] args) {
		String [] as = {"2", "1", "#", "#", "3", "#", "#"};
		ArrayList<String> arrayString  = new ArrayList<String>(Arrays.asList(as));
		SerializeBst ds = new SerializeBst(); 
		BstTreeNode root = ds.deserializeTree(arrayString);
		//root = null;
		arrayString = ds.serializeTree(root);
		
		
		
	}
	
}
