/*
Time Complexity: O(n n!); n! for all permutations, n for string insertion in set (average)
Space Complexity: O(n n!); n! for all permutations, n for string length
*/

void permutations(string s, set<string>& perm, vector<bool> available, int index = 0, string t = "") {
    if(index == s.length()) {
        perm.insert(t);
        return;
    }

    for(int i = 0; i < s.length(); i++) {
        if(!available[i])
            continue;

        available[i] = false;
        permutations(s, perm, available, index + 1, t + s[i]);
        available[i] = true;
    }
}

// Demonstration
int main() {
    string s;
    cin >> s;
    
    set<string> perm;
    vector<bool> available(s.length(), true);
    
    permutations(s, perm, available);
    
    for(auto e : perm)
        cout << e << " ";

    return 0;
}
