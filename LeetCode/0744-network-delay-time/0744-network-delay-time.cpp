class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for(auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [curDist, node] = pq.top();
            pq.pop();

            if(curDist > dist[node]) continue;

            for(auto& [nei, weight] : graph[node]) {
                int newDist = curDist + weight;

                if (newDist < dist[nei]) {
                    dist[nei] = newDist;
                    pq.push({newDist, nei});
                }
            }
        }

        int answer = 0;

        for(int node = 1; node <= n; ++node) {
            if(dist[node] == INT_MAX){
                return -1;
            }

            answer = max(answer, dist[node]);
        }

        return answer;
    }
};