int countIntervals(vector<pair<int,int>>& intervals) {
	vector<pair<int,int>> v = intervals; // O(n) space
	
	sort(v.begin(), v.end(),
         [](const pair<int, int>& a,
            const pair<int, int>& b) {
             return a.second < b.second;
         });

	int ans = 0, last_finish_time = 0;

	for(auto interval : v) { // O(n) time
		if(interval.first >= last_finish_time) {
			ans++;
			last_finish_time = interval.second;
		}
	}

	return ans;
}
