/*
	Time Complexity: O(n)
 	Space Complexity: O(n)
*/

vector<vector<int>> tree;
vector<int> A;  // To store whether each node is good (1) or bad (0)
int C;

int dfs(int node = 0, int parent = -1, int good_count = 0) {
    if (A[node] == 1) good_count++;
    
    if (good_count > C) return 0;

    bool is_leaf = true;
    int valid_paths = 0;
    
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            is_leaf = false;
            valid_paths += dfs(neighbor, node, good_count);
        }
    }

    if (is_leaf) return 1;

    return valid_paths;
}
