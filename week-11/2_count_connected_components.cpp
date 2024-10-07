/*
Time Complexity: O(A + B.size()), proportional to number of vertices & number of edges
Space Complexity: O(A + B.size()), proportional to number of vertices & number of edges
*/

void DFS(vector<vector<int>>& adj, vector<bool>& visited, int vertex) {
    for(auto neighbour : adj[vertex]) {
        if(!visited[neighbour]) {
            visited[neighbour] = true;
            DFS(adj, visited, neighbour);
        }
    }
}

int countConnectedComponents(vector<vector<int>>& adj) {
	vector<bool> visited(adj.size(), false);
    int count = 0;

    for(int vertex = 0; vertex < adj.size(); vertex++) {
        if(!visited[vertex]) {
            DFS(adj, visited, vertex);
            count++;
        }
    }

    return count;
}

// Demonstration
int main() {
    int A = 4;
    vector<pair<int, int>> B = {{1, 2}, {2, 3}};

	vector<vector<int>> adj(A);

    for(auto edge : B) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    cout << countConnectedComponents(adj);

    return 0;
}
