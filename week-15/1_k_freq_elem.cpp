/*
	Time Complexity: O(n log k)
 	Space Complexity: O(n)
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
	
    for (int num : nums)
        frequencyMap[num]++;
    
    auto cmp = [&](int a, int b) { return frequencyMap[a] > frequencyMap[b]; };
    priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);

    for (auto& [num, freq] : frequencyMap) {
        minHeap.push(num);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    
    vector<int> result;
	
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}
