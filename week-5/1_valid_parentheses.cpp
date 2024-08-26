/*
	n = s.length()
	Time Complexity: O(n), due to iterating through the entire input string
 	Space Complexity: O(n), Ex: "(((]" (need to store all 4 characters in stack)
*/

bool valid_parentheses(string s) {
	stack<char> paran;

	// Iterate through the entire string
	for(auto c : s) {
		// Opening parantheses can always be pushed
		if(c == '(' || c == '{' || c == '[') 
            paran.push(c);
		else {
			// Closing parantheses cannot be at the beginning
			if(paran.empty()) {
				paran.push(c);
				break;
			}
			
			char p = paran.top();

			// Opening & closing parantheses of the same type can be adjacent, Ex: "()"
			if((p == '(' && c == ')') || (p == '{' && c == '}') || (p == '[' && c == ']'))
				paran.pop();
			// Opening & closing parantheses of different type can't be adjacent, Ex: "(]"
			else {
				paran.push(c);
				break;
			}
		}
	}

	// A valid parantheses string should yeild an empty stack
	if(paran.empty())
		return true;
	else
		return false;
}
