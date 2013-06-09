	vector<string> fullJustify(vector<string> &words, int L) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vector<vector<string> > vs;
		//pack words
		int i = 0;
		while (i< words.size()) {
			int k = L;
			vector<string> s;
			while (i < words.size() && k>=0 ) {
				if (k >= words[i].size()) {  //BUG
					k = k-words[i].size()-1;  //BUG1 
					s.push_back(words[i]);
					++i;
				} else {
					break;  //BUG2
				}
			}
			vs.push_back(s);
		}

		vector<string> result;
		//process
		for (int i = 0; i< vs.size(); ++i) {
			if (vs[i].size() ==1) {
				string s = vs[i][0] + string(L-vs[i][0].size(), ' ');
				result.push_back(s);
			} else if (i == vs.size()-1) {
				string s(vs[i][0]);
				for (int j = 1; j < vs[i].size(); j++)
					s += " " + vs[i][j];
				s += string(L-s.size(), ' ');
				result.push_back(s);    
			} else {
				//calculate space
				//total space
				int slength =0;
				for (int j =0; j< vs[i].size() ; j++) {
					slength += vs[i][j].size();
				}
				int es = (L - slength)/(vs[i].size()-1);
				int ls = (L- slength - es*(vs[i].size()-2));
				//pr string
				string s;
				s += vs[i][0] + string(ls, ' ');
				for (int j = 1; j < vs[i].size() -1; j++) {
					s += vs[i][j] + string(es, ' ');
				}
				//last one
				s += vs[i][vs[i].size()-1];
				result.push_back(s);		  
			}
		}
		return result;      
	}
