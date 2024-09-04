/*
Time Complexity: O((m + n)log(m + n))
Space Complexity: O(m + n)
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

void mergeAndSort(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	for(int i = m; i < m + n; i++)
    nums1[i] = nums2[i - m];
	mergeSort(nums1, 0, m + n - 1);
}
