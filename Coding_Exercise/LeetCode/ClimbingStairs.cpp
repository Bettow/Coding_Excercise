	int climbStairs(int n) {
        	int t1 = 0;
        	int t2 = 1;
        
        	int ret = 0;
        	while (n--) {
            		ret = t1+t2;
            		t1 = t2;
            		t2  = ret;
        	}
        
        	return ret;
	}
