public class Solution {
    public ArrayList<Integer> findSubstring(String S, String[] L) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (L == null || L.length ==0)
            return null;
            
        int m = L.length;
        int n = L[0].length();
        Map<String, Integer> target = new HashMap<String, Integer>();
        for (int i =0; i< m; i++) {
            if (target.containsKey(L[i])) {
                target.put(L[i], target.get(L[i])+1);
            } else {
                target.put(L[i],1);
            }
        }
        
        ArrayList<Integer> ret = new ArrayList<Integer>();
        for (int i =0; i <= S.length()-n*m; i++) {
            Map<String, Integer> curr = new HashMap<String, Integer>(target);
            int j =0;
            for (; j < m; j++) {
                String word = S.substring(i+j*n, i+j*n+n);
                if (curr.containsKey(word)) {
                    curr.put(word, curr.get(word)-1);
                    if (curr.get(word)<0)
                        break;
                } else {
                    break;
                }
            }
            if (j==m)
                ret.add(i);
        }
        return ret;
    }
}