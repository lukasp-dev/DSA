/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && knows(i, j)){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> outbound(n, 0);
        vector<int> inbound(n, 0);

        for(int i=0; i<n; i++){
            for(int nei : adj[i]){
                outbound[i] = adj[i].size();
                inbound[nei]++;
            }
        }

        for(int i=0; i<n; i++){
            if(outbound[i]==0 && inbound[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};