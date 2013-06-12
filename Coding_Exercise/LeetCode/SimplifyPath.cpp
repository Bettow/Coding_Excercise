string simplifyPath(string path) {
	if (path.empty())
		return ("");

	int i = 0;
	stack<string> ss;
	string result;
	while (i < path.size()){
		//do 
		if (path[i] == '/') {
			//result += "/";
			while(i < path.size() && path[i] == '/') i++;
			if (i == path.size()) break;
			//find next word
			int j = i;
			while (j < path.size() && path[j] != '/') j++;
			string dir = path.substr(i, j-i);
			if (dir == "..") {
				if (!ss.empty())
					ss.pop();
			} else if (dir != ".") {
				ss.push(dir);
			}
			i = j;
		}

	}

	if (ss.empty()) {
		return ("/");
	} else {
		while (!ss.empty()) {

			result = ss.top() + result;
			result = "/" + result;
			ss.pop();
		}
	}
	return result;

}