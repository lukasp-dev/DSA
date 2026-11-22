class Solution {
private:
    const int MOD = 1e9 + 7;

    int dfs(int node, const vector<vector<int>>& prev, vector<int>& memo) {
        if(node == 0) return 1;
        if(memo[node] != -1) {
            return memo[node];
        }

        int total = 0;

        for(auto& parent : prev[node]) {
            total = (total + dfs(parent, prev, memo)) % MOD;
        }

        memo[node] = total;
        return total;
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        vector<long long> dst(n, 1LL << 60); dst[0] = 0;
        vector<vector<int>> prev(n); 

        for(auto& road : roads) {
            int from = road[0];
            int to = road[1];
            int time = road[2];

            adj[from].push_back({time, to});
            adj[to].push_back({time, from});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // wei, node

        while(!pq.empty()){
            auto [wei, curr_node] = pq.top(); pq.pop();
            if (wei != dst[curr_node]) continue;

            for(auto& [time, next_node] : adj[curr_node]) {
                long long new_cost = wei + time;
                if(dst[next_node] > new_cost) {
                    // 기존에 있었던 prev node 들을 flush 하고 새로운 {prev}로
                    prev[next_node] = {curr_node};
                    
                    dst[next_node] = new_cost;
                    pq.push({new_cost, next_node});
                } else if(dst[next_node] == new_cost){
                    prev[next_node].push_back(curr_node);
                }
            }
        }

        vector<int> memo(n, -1);
        return dfs(n-1, prev, memo);
    }
};