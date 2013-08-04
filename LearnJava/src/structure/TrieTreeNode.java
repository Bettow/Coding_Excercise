package structure;

import java.util.ArrayList;

public class TrieTreeNode {
	private boolean isLeaf;
	private TrieTreeNode [] children;
	private String cWord;
	private String word;
	private int numOfChildren ;
	public TrieTreeNode() {
		children = new TrieTreeNode[27];
		this.isLeaf = false;
		numOfChildren = 0;
	}
	
	public void setIsLeaf(boolean isLeaf) {
		this.isLeaf = isLeaf;
	}
	
	public boolean getIsLeaf() {
		return isLeaf;
	}
	
	public void setWord(String s) {
		word = s;
	}
	
	public String getcWord() {
		return cWord;
	}
	
	public void compressWord() {
		int l = word.length();
		if (l > 2) {
			cWord = word.charAt(0) + Integer.toString(l-2) + word.charAt(l-1);					
		}	
	}
	
	public TrieTreeNode [] getChildren() {
		return children;
	}
	
	public void insertChild(char c) {
		children[c-'a'] = new TrieTreeNode();
		numOfChildren++;
	}
	
	public int getNumOfChildren() {
		return numOfChildren;
	}

}
