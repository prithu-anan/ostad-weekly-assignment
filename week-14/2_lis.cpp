/*
	Time Complexity: O(n log n)
 	Space Complexity: O(n)
*/

int longestIncreasingSubsequence(vector<int>& nums) {
    vector<int> lis;

    for (int num : nums) {
		// binary search
        auto it = lower_bound(lis.begin(), lis.end(), num);
        
        if (it == lis.end())
            lis.push_back(num);
        else 
            *it = num;
        }
    }

    return lis.size();
}
