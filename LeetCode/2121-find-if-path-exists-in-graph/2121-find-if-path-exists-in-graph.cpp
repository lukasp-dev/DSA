class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int destination, int node) {
        if(node == destination) return true;
        visited[node] = 1;

        for(int nei : adj[node]) {
            if(!visited[nei]) {
                bool found = dfs(adj, visited, destination, nei);
                if(found) return true;
            }
        }
        
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        vector<int> visited(n, 0);
        return dfs(adj, visited, destination, source);
    }
};