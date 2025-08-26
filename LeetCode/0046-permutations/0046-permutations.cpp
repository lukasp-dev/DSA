class Solution {
public:
    void makePermutations(vector<int>& nums, vector<vector<int>>& ret, vector<int>& visited, int n, vector<int>& vec){
        if(vec.size() == n){
            ret.push_back(vec);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                vec.push_back(nums[i]);
                visited[i] = 1;
                makePermutations(nums, ret, visited, n, vec);
                visited[i] = 0;
                vec.pop_back();
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> vec;
        vector<int> visited(n+1, 0);
        makePermutations(nums, ret, visited, n, vec); 
        return ret;
    }
};