public class longestValidParentheses {
    public int longestValidParentheses(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (s.length() == 0)
            return 0;
            
        int left =0;
        int ret = 0;
        Stack<Integer> si = new Stack<Integer>();            
        for (int i =0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                si.push(i);
            } else {
                if (!si.isEmpty()) {
                    si.pop();  //BUG
                    int r = 0;
                    if (si.isEmpty()) {
                        r = i-left+1;                       
                    } else {
                        r = i-si.peek();
                    }
                    ret = Math.max(ret, r);
                } else {
                    left = i+1;
                    
                }
            }
        }
        return ret;
    }
}