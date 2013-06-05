	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> result(2, 0);

		if(numbers.size() < 2){
			return result;
		}

		map<int, int> imap;
		for (int i = 0; i < numbers.size(); ++i) {
			if (imap.find(numbers[i]) != imap.end())
				imap[numbers[i]] = i;
			else	
				imap.insert(make_pair(numbers[i],i));  
		}

		for (int i = 0; i < numbers.size(); ++i) {
			int indx2 = target - numbers[i];
			if (imap.find(indx2) != imap.end()){
				if (i <= imap[indx2]) {
					result[0] = i+1;
					result[1] = imap[indx2]+1;
				} else {
					result[0] = imap[indx2]+1;
					result[1] = i+1;
				}
                return result;
			}
		}
		//return if not found      

	}