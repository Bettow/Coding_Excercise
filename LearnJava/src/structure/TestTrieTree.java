package structure;

public class TestTrieTree {
	private TrieTreeNode root;
	public void createTree() {
		root = new TrieTreeNode();		
	}
	public void insertTree(String s) {
		TrieTreeNode curr = root;
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);					
			if (curr.getChildren()[c] == null) {
				curr.insertChild(c);
			}
			curr = curr.getChildren()[c];
		}
		curr.setIsLeaf(true);
	}
	
	public void compressTree(TrieTreeNode root) {
		
		
	}
	
	public TrieTreeNode getTree() {
		return root;
	}
	
	public static void main(String [] args) {
		TestTrieTree t = new TestTrieTree();
		t.createTree();
		t.insertTree("international");
		
		
	}
}
