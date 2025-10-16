/* The knows API is defined for you.
      bool knows(int a, int b); */

void print(vector<vector<int>>& adj){
    for(auto& nei : adj){
        for(int i : nei){
            cout << i << " ";
        }
        cout << "\n";
    }
}

class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<int>> adjList(n+1, vector<int>());

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && knows(i, j)){
                    adjList[i].push_back(j);
                }
            }
        }

        print(adjList);

        vector<int> inbound(n, 0);
        vector<int> outbound(n, 0);

        for(int i=0; i<n; i++){
            int outBoundSize = adjList[i].size();
            outbound[i] = outBoundSize;
            for(int j=0; j<outBoundSize; j++){
                int toIndex = adjList[i][j];
                inbound[toIndex]++;
            }
        }

        for(int i=0; i<n; i++){
            if(inbound[i] == n-1 && outbound[i]==0){
                return i;
            }
        }

        return -1;
    }
};