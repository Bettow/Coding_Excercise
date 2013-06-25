package leetcode;

import structure.TrieNode;

public class LongestRepSubString {
	public int insertNode(TrieNode root, String s) {
		int counter = 0;
		TrieNode currNode = root;
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			TrieNode node = currNode.getSib(c);
			if (node == null) {
				TrieNode n = new TrieNode(c);
				currNode.getSibsNode().add(n);
				currNode = n;
			} else {
				currNode = node;
				counter++;
			}
		}
		return counter;
	}
	
	public int LongestRepString(String s) {
		int max = 0;
		TrieNode root = new TrieNode('0');
		for (int i = 0; i < s.length(); ++i) {
			String n = s.substring(i);
			max = Math.max(max, insertNode(root, n));
		
		}
		return max;
		
	}
	
	public static void main(String [] args) {
		String s = "abcabc";
		LongestRepSubString o = new LongestRepSubString();
		int k = o.LongestRepString(s);
		System.out.println("Result : " + k);
	
	}
}
