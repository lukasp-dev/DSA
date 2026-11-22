class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        vector<double> dst(n, 0);
        dst[start_node] = 1;

        for(int i=0; i<edges.size(); ++i) {
            int from = edges[i][0];
            int to = edges[i][1];

            adj[from].push_back({succProb[i], to});
            adj[to].push_back({succProb[i], from});
        }

        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
        pq.push({1, start_node});

        while(!pq.empty()) {
            auto[wei, curr_node] = pq.top(); pq.pop();
            
            if(wei != dst[curr_node]) {
                continue;
            }

            for(auto& [prob, nei_node] : adj[curr_node]) {
                double new_prob = wei * prob; 

                if(new_prob > dst[nei_node]) {
                    dst[nei_node] = new_prob;
                    pq.push({new_prob, nei_node});
                }
            }
        }

        return dst[end_node];
    }
};