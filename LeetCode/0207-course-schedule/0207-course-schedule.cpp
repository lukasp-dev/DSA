class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& status, int node){
        if(status[node] == 1) return false;
        if(status[node] == 2) return true;

        status[node] = 1;

        for(int nextNode : adj[node]){
            if(!dfs(adj, status, nextNode)) return false;
        }

        status[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> status(numCourses, 0);

        for(vector<int>& preq : prerequisites){
            adj[preq[1]].push_back(preq[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(adj, status, i)) return false;
        }

        return true;
    }
};