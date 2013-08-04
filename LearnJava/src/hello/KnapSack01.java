package hello;

import java.util.ArrayList;
import java.util.Arrays;

public class KnapSack01 {
	public void knapsack(ArrayList<Integer> cost, ArrayList<Integer> value, int totalCost) {
		int m = cost.size();
		int [][] table = new int[m+1][totalCost+1];
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= totalCost; ++j) {
				table[i][j] = 0;
			}
		}
		
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= totalCost; ++j) {
				if ( j >= cost.get(i-1)) {
					table[i][j] = Math.max(table[i-1][j], table[i-1][j-cost.get(i-1)]+ value.get(i-1));
				}
			}
		}
		
		prettyPrint(table);
		
		
	}
	
	public void knapsackS(ArrayList<Integer> cost, ArrayList<Integer> value, int totalCost) {
		int m = cost.size();
		int [] table = new int[totalCost+1];
			for (int j = totalCost; j >=0; --j) {
				table[j] = 0;
			}

		
/*		for (int i = 1; i <= m; ++i) {
			for (int j = totalCost; j >0; --j) {
				if ( j >= cost.get(i-1)) {
					table[j] = Math.max(table[j], table[j-cost.get(i-1)]+ value.get(i-1));
				}
			}
		}
		*/
			
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= totalCost; ++j) {
					if ( j >= cost.get(i-1)) {
						table[j] = Math.max(table[j], table[j-cost.get(i-1)]+ value.get(i-1));
					}
				}
			}
		
		//prettyPrint(table);
		
		
	}
	
	public void prettyPrint(int [][] array) {
		int m = array.length;
		int n = array[0].length;
		for (int i = 0; i < m; ++i) {
			System.out.println("");
			for (int j = 0; j < n; ++j) {
				System.out.print(array[i][j] + "   ");
			}
		}
		
	}
	
	public static void main(String[] arg) {
		Integer a[] = {5,7,8};
		Integer b[] = {3,4,5};
		ArrayList<Integer> cost = new ArrayList<Integer>(Arrays.asList(b));
		ArrayList<Integer> value = new ArrayList<Integer>(Arrays.asList(a));
		KnapSack01 o = new KnapSack01();
		o.knapsackS(cost, value, 10);
		
	}
}


