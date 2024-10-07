/*
Time Complexity: O(N + edges.size()), proportional to number of vertices & number of edges
Space Complexity: O(N + edges.size()), proportional to number of vertices & number of edges
*/

bool validPath(vector<vector<int>> adj, int src, int dst) {
	queue<int> vertices;
	vector<int> visited(adj.size(), false);
	vertices.push(src);

	while(!vertices.empty()) {
		int u = vertices.front();
		vertices.pop();
		visited[u] = true;

		for(auto v : adj[u]) {
			if(!visited[v]) {
				if(v == dst)
					return true;
				
				vertices.push(v);
			}
		}
	}
			
	return false;
}

// Demonstration
int main() {
    int N = 6;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    
    vector<vector<int>> adj(N);
    
    for(auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    cout << validPath(adj, 0, 5);

    return 0;
}
