package mit;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

import structure.GraphNode;

public class CloneGraph {
	GraphNode clone(GraphNode node) {
		if (node == null)
			return null;
		HashMap<GraphNode, GraphNode> map = new HashMap<GraphNode, GraphNode>();
		Queue<GraphNode> q = new LinkedList<GraphNode>();
		q.add(node);
		GraphNode newRoot = new GraphNode();
		map.put(node, newRoot);
		while(!q.isEmpty()) {
			GraphNode n = q.poll();
			for (GraphNode c : n.children) {
				if (!map.containsKey(c)) {
					GraphNode newNode = new GraphNode();
					newNode.val = n.val;
					map.get(n).children.add(newNode);
					map.put(c, newNode);
					q.add(c);					
				} else {
					map.get(n).children.add(map.get(c));
				}
			}
			
		}
		
		return newRoot;
		
	}

}
