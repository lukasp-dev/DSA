class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adj[from].push_back({to, price});
        }

        const int maxFlights = k + 1;
        const int INF = 1e9;

        // dist[city][used] = cheapest cost using exactly used flights.
        vector<vector<int>> dist(n, vector<int>(maxFlights + 1, INF));
        dist[src][0] = 0;

        // {total cost, current city, flights used}
        using Entry = tuple<int, int, int>;
        priority_queue<Entry, vector<Entry>, greater<Entry>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, city, used] = pq.top();
            pq.pop();

            if (cost != dist[city][used]) {
                continue;
            }

            if (city == dst) {
                return cost;
            }

            if (used == maxFlights) {
                continue;
            }

            for (const auto& [next, price] : adj[city]) {
                int nextCost = cost + price;
                int nextUsed = used + 1;

                if (nextCost < dist[next][nextUsed]) {
                    dist[next][nextUsed] = nextCost;
                    pq.push({nextCost, next, nextUsed});
                }
            }
        }

        return -1;
    }
};