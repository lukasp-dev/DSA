class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, int n){
        visited[node] = 1;
        for (int i = 0; i < n; ++i) {
            if (adj[node][i] == 1 && !visited[i]) {
                dfs(adj, visited, i, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adj, visited, i, n);
                ++count; 
            }
        }
        return count;
    }
};
