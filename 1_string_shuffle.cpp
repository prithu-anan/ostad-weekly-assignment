/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

string restoreString(string s, vector<int>& indices) {
    int n = s.length();
    vector<char> str(n); // O(n) space
    string ans; // O(n) space
    for(int i = 0; i < n; i++) // O(n) time
        str[indices[i]] = s[i];
    for(auto c : str) // O(n) time
        ans += c;
    return ans;
}

/*
Explanation:
Puts the characters of the given string into an array according to the positions indicated by the indices array.
Converts the array of characters into a string and then prints the string.
*/
