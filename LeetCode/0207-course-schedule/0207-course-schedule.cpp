class Solution {
private:
    bool isCycle(vector<vector<int>>& adj, vector<int>& status, int node) {
        if(status[node] == 1) return true;
        if(status[node] == 2) return false;
        
        status[node] = 1;

        for(int nei : adj[node]) {
            bool cycle = isCycle(adj, status, nei);
            if(cycle) return true;
        }

        status[node] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> status(numCourses, 0);
        
        vector<vector<int>> adj(numCourses);

        for(auto preq : prerequisites) {
            adj[preq[1]].push_back(preq[0]);
        }

        for(int i=0; i<numCourses; ++i) {
            if(isCycle(adj, status, i)) {
                return false;
            }
        }

        return true;
    }
};