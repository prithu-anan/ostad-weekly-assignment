/*
	Time complexity: O(n), due to iterating through the entire string
 	Space Complexity: O(n), worst case: no adjacent duplicate characters
*/

string removeDuplicates(string s) {
	stack<char> dup;

	// Iterating through the string
	for(auto c : s) {
		if(dup.empty() || c != dup.top()) 
			dup.push(c);
		else
			dup.pop(); // Remove adjacent duplicates
	}

	string ans(dup.size(), '0');
	int i = dup.size() - 1;

	// Construct the new string from the stack
	while(!dup.empty()) {
		ans[i--] = dup.top();
		dup.pop();
	} 
	
	return ans;
}
