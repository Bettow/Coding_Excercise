package leetcode;

public class editDistanceRec {
    public int minDistance(String a, String b) {
        if (a == null && b== null)
            return 0;
		if (a == null || a.length() == 0)
			return b.length();
		if (b == null || b.length() == 0)
			return a.length();
            
		
		char ca = a.charAt(0);
        String ra, rb;
        if (a.length() !=1)
		    ra = a.substring(1);
        else 
            ra = null;
		char cb = b.charAt(0);
		if (b.length() != 1)
            rb = b.substring(1);
	    else
            rb = null;
        
        int mind = minDistance(ra, rb);
		if (ca == cb) {
			return mind;
		} else {
            
			int d = Math.min(mind, minDistance(a, rb));
            return Math.min(d,minDistance(ra, b))+1;
		}		
	}

}
