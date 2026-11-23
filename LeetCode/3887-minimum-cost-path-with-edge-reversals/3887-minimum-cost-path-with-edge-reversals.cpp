class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dst(n, 1e9);
        dst[0] = 0;

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({w, v});
            adj[v].push_back({2*w, u});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // wei, node

        while(!pq.empty()) {
            auto [wei, curr_node] = pq.top();
            pq.pop();

            if(dst[curr_node] != wei) {
                continue;
            }

            for(auto& [cost, next_node] : adj[curr_node]) {
                int new_cost = dst[curr_node] + cost;
                if (new_cost < dst[next_node]){
                    dst[next_node] = new_cost;
                    pq.push({new_cost, next_node});
                }
            }
        }

        return dst[n-1] == 1e9 ? -1 : dst[n-1];
    }
};