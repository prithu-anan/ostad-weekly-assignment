/*
Time Complexity: O(nlogn), [logn for splitting in half in each iteration, n for going through the elements]
Space Complexity: O(n), [temporary array may have a maximum size of n duirng the final merge]

This approach is best fitted for the given problem because it complies with the given time & space constraints.
Once we have done sorting in O(nlogn) time, we just need to access the kth largest element in O(1) time.

Here's why other algorithm wouldn't have worked:
-> Bubble, Insertion & Selection Sort: O(n^2) time complexity
-> Counting Sort: Not suitable for negative numbers
-> Quick Sort: O(n^2) time complexity if pivot is choosen poorly

So, Merge Sort seemed the best option
*/

void merge(vector<int>& nums, int left, int mid, int right) {
	vector<int> merged;
	int i = left, j = mid + 1;
	
	while(i <= mid && j <= right) {
		if(nums[i] < nums[j])
			merged.push_back(nums[i++]);
		else
			merged.push_back(nums[j++]);
	}

	while(i <= mid)
		merged.push_back(nums[i++]);
	while(j <= right)
		merged.push_back(nums[j++]);

	for(i = left; i <= right; i++)
		nums[i] = merged[i - left];
}

void mergeSort(vector<int>& nums, int left, int right) {
	if(left >= right) return;
	
	int mid = (left + right) / 2;

	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

int kthLargestElement(vector<int>& nums, int k) {
	int ans = nums.size() - k;
	mergeSort(nums, 0, nums.size() - 1);
	return nums[ans];
}
