package mit;

import java.util.HashSet;

public class TrieNode {
	private HashSet<TrieNode> sibs;
	private char key;
	public TrieNode(char c) {
		this.key = c;
		sibs = new HashSet<TrieNode>();
	}
	
	public HashSet<TrieNode> getSibsNode() {
		return this.sibs;
	}
	
	public char getKey () {
		return this.key;
	}
	
	public TrieNode getSib(char c) {
		if (sibs == null)
			return null;
		else
			for (TrieNode node : sibs) {
				if (node.getKey() == c) {
					return node;
				}	
			}
		return null;
	}

}
