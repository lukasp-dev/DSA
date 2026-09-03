class Solution {
    void go(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        visited[node] = true;

        for(int i = 0; i < isConnected[node].size(); i++) {
            if(!visited[i] && isConnected[node][i]) {
                go(isConnected, visited, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int total_number = 0;
        int n = isConnected.size();
        
        if(n == 0) return 0;

        vector<bool> visited(n, false);

        for(int i=0; i<n; i++) {
            if(visited[i]) continue;
            
            go(isConnected, visited, i);

            total_number++;
        }

        return total_number;
    }
};