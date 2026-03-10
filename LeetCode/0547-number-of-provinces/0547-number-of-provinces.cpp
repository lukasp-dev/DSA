class Solution {
public:
    void dfs(vector<int>& visited, vector<vector<int>>& isConnected, int idx){
        visited[idx] = 1;
        
        for(int i=0; i < isConnected[idx].size(); i++){
            if(!visited[i] && isConnected[idx][i]){
                dfs(visited, isConnected, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ret = 0;
        vector<int> visited(n, 0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(visited, isConnected, i);
                ret++;
            }
        }

        return ret;
    }
};