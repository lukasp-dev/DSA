class Solution {
public:
    void makeCombi(vector<int>& vec, vector<vector<int>>& ret, vector<int>& nums, vector<int>& visited, int n, int start, int k){
        if(vec.size() == k){
            ret.push_back(vec);
            return;
        }

        for(int i=start; i<n; i++){
            if(!visited[i]){
                visited[i] = 1;
                vec.push_back(nums[i]);
                makeCombi(vec, ret, nums, visited, n, i+1, k);
                visited[i] = 0;
                vec.pop_back();
            }
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        ret.push_back({});

        for(int i=1; i<=n; i++){
            vector<int> vec;
            vector<int> visited(n, 0);
            makeCombi(vec,ret,nums, visited, n, 0, i);
        }
        
        return ret;
    }
};