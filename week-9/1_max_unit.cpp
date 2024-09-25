int maxUnit(vector<pair<int,int>>& boxTypes, int truckSize) {
	vector<pair<int,int>> v = boxTypes; // O(n) space
	
	sort(v.begin(), v.end(),
         [](const pair<int, int>& a,
            const pair<int, int>& b) {
             return (float) a.second / a.first > (float) b.second / b.first;
         });

	int ans = 0;

	for(auto box : v) { // O(n) time
		if(box.first <= truckSize) {
			ans += box.first * box.second;
			truckSize -= box.first;
		}
		else {
			ans += truckSize * box.second;
			break;
		}
	}

	return ans;
}
