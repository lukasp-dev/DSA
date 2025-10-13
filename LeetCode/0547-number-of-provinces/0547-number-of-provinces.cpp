class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int node){
        visited[node] = 1;

        vector<int> canGo = isConnected[node];
        
        for(int i=0; i<canGo.size(); i++){
            if(canGo[i]==1 && !visited[i]){
                dfs(isConnected, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // isConnected.size() returns the length of only one row
        vector<int> visited(n, 0);
        int count = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
};