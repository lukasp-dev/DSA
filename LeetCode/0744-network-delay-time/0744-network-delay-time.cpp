class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(vector<int>& time : times) {
            int src = time[0], dst = time[1], wei = time[2];
            adj[src].push_back({dst, wei}); //dst, wei
        }

        priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> pq;

        vector<int> dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if(dist[node] < dis) continue;

            for(auto& [dst, wei] : adj[node]) {
                int newDist = dis + wei;
                if(dist[dst] > newDist) {
                    dist[dst] = newDist;
                    pq.push({newDist, dst});
                }
            }
        }

        int _max = 0;

        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            _max = max(_max, dist[i]);
        }

        return _max;
    }
};