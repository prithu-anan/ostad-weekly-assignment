/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/

int findMin(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	int mid = left + (right - left) / 2;
	int minimum = INT_MAX;
	
	while(left <= right){
		minimum = min(minimum, nums[mid]);
		
		if(nums[left] < nums[right]) 
			return min(minimum, nums[left]);
		
		if(nums[mid] >= nums[left]) 
			left = mid + 1;
		else 
			right = mid - 1;
		
		mid = (left + right) / 2;
	}
	
	return minimum;
}
