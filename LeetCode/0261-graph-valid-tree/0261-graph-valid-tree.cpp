class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n, vector<int>());
        

        for(int i = 0; i < edges.size(); i++){
            int node = edges[i][0];
            int nei = edges[i][1];

            adj[node].push_back(nei);
            adj[nei].push_back(node);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({-1, 0});
        visited.insert(0);

        while(!q.empty()){
            auto [parent, curr] = q.front(); q.pop();

            for(int nei : adj[curr]){
                if (nei == parent) continue; // 부모는 무시
                if (visited.count(nei)) return false; // 진짜 사이클
                visited.insert(nei);
                q.push({curr, nei});
            } 
        }

        return visited.size() == n;
    }
};