class Solution {
private:
    bool isCyclic(vector<vector<int>>& adj, vector<int>& status, int node) {
        if(status[node] == 1) return true;
        if(status[node] == 2) return false;

        status[node] = 1;

        for(int nei : adj[node]) {
            if(isCyclic(adj, status, nei)){
                return true;
            }
        }

        status[node] = 2;
        return false;
    }

    void setRoute(vector<vector<int>>& adj, vector<int>& route, vector<bool>& visited, int node) {
        visited[node] = true;

        for(int nei : adj[node]) {
            if(!visited[nei]) setRoute(adj, route, visited, nei);
        }

        route.push_back(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> status(numCourses, 0);

        vector<vector<int>> adj(numCourses);
        for(auto& preq : prerequisites) {
            adj[preq[1]].push_back(preq[0]);
        }

        for(int i=0; i<numCourses; i++) {
            if(isCyclic(adj, status, i)) {
                return {};
            }
        }

        vector<int> route;
        vector<bool> visited(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]) setRoute(adj, route, visited, i);
        }
        reverse(route.begin(), route.end());
        return route;
    }
};