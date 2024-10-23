/*
	Time Complexity: O(V + E)
 	Space Complexity: O(V)
*/

bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack)) 
                return true;
        } 
		else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool containsCycle(int A, vector<vector<int>>& graph) {
    vector<bool> visited(A, false);
    vector<bool> recStack(A, false);

    for (int i = 0; i < A; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack)) {
                return true; 
            }
        }
    }

    return false; 
}
