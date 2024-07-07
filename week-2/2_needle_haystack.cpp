/*
TIme Complexity: O(nh) due to comparing strings on length n in a loop which iterates a maximum of O(h-n-1)
Space Complexity: O(n), due to generating temporary substrings using substr function
*/

int calcHash(string s){
    int size = s.length();
    int hash = 0;
    for(auto c : s) hash += (c - 'A'); // O(size) time
    return hash;
}

int strStr(string haystack, string needle) {
    int i, h = haystack.length(), n = needle.length();
    int diff = h - n;
    int n_hash = calcHash(needle); // O(n) time
    int h_hash = calcHash(haystack.substr(0, n)); // O(n) time & O(n) space
    if(n_hash == h_hash)
        if(needle == haystack.substr(0, n)) // O(n) time & O(n) space
            return 0;
    
    for(i = 1; i <= diff; i++) { // O(h-n+1) time
        h_hash = h_hash - haystack[i - 1] + haystack[i + n - 1];
        if(n_hash == h_hash)
            if(needle == haystack.substr(i, n)) // O(n) time
                return i;
    }

    return -1;
}

/*
Explanation:
Takes a window of haystack which has the same length as needle.
Calculates their hash using a very basic hash function.
Compares the window and needle only if their hash values match.
This avoids unnecessary string comparsions to a great extent, reducing time complexity.
The window is slid forward and the new hash is computed using rolling hash technique.
This ensures that the calcHash function is called only twice and hence, time complexity is reduced.
Starting index is returned if the window and the needle are same.
*/
