/*
Time Complexity: O(N^2), due to each cell being visited once in each case
Space Complexity: O(N^2), due to grid size
*/

bool findPath(vector<vector<bool>>& grid, vector<vector<bool>>& visited, int n = 0, int m = 0) {
    visited[n][m] = true;
    
    if(!grid[n][m])
        return false;
    
    int N = grid.size();
    int M = grid[0].size();

    if(n == N - 1 && m == M - 1) 
        return true;

    if((n + 1 < N) && grid[n + 1][m] && !visited[n + 1][m])
        if(findPath(grid, visited, n + 1, m))
            return true;

    if((m + 1 < M) && grid[n][m + 1] && !visited[n][m + 1])
        if(findPath(grid, visited, n, m + 1))
            return true;
        
    if((n - 1 > -1) && grid[n - 1][m] && !visited[n - 1][m])
        if(findPath(grid, visited, n - 1, m))
            return true;

    if((m - 1 > -1) && grid[n][m - 1] && !visited[n][m - 1])
        if(findPath(grid, visited, n, m - 1))
            return true;

    return false;
}

// Demonstration
int main() {
    int N, c;
    cin >> N;
    vector<vector<bool>> grid(N, vector<bool>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for(int n = 0; n < N; n++) {
        for(int m = 0; m < N; m++) {
            cin >> c;
            grid[n][m] = c;
        }
    }

    cout << findPath(grid, visited) << endl;
    
    return 0;
}
