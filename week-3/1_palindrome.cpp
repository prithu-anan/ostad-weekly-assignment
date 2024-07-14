/*
Assuming n = s.length()
Time Complexity: O(n), the recursive function is called at most n/2 times and doesn't contain any loop
Space Complexity: O(n), the recursive function is called at most n/2 times and no additional space is used
*/

bool checkPalindrome(string s, int left, int right) {
    if(left >= right) return true;
    if(s[left] != s[right]) return false;
    return checkPalindrome(s, left + 1, right - 1);
}

bool isPalindrome(string s) {    
    return checkPalindrome(s, 0, s.length() - 1);
}

/*
Explanation:
This is a variation of two pointers.
Instead of iteration, we are using recursion.

Recursive Case: In each call, 
the left pointer is moved one character forward and
the right pointer is moved one character backward.

Base Case:
One mismatch is sufficient to declare that the string isn't a pallindrome
The recursion is also terminated if the pointers meet each other, implying that the string is a palindrome
*/
