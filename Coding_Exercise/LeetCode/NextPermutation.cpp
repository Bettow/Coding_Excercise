	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (num.size() <=1)
			return;

		int search_indx = num.size()-1;
		while (search_indx >0) {
			if( num[search_indx-1] < num[search_indx])
				break;
			search_indx--;
		}

		if (search_indx ==0) {
			rev(num, search_indx, num.size()-1);
			return;
		}       

		//search forward
		int s1 = search_indx -1;
		while (search_indx< num.size() && num[s1] < num[search_indx]) {
			search_indx++;
		}
		search_indx--;
		swap(num[s1], num[search_indx]);
		rev(num, s1+1, num.size()-1);
	}

	void rev(vector<int> &num, int st, int ed) {
		while (st< ed) {
			swap(num[st], num[ed]);
			st++;
			ed--;
		}
	}