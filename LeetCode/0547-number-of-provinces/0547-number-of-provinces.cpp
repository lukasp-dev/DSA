class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int node) {
        visited[node] = 1;

        for (int nei = 0; nei < isConnected.size(); ++nei) {
            if (isConnected[node][nei] == 1 && !visited[nei]) {
                dfs(isConnected, visited, nei);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
};