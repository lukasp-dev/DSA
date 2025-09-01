class Solution {
public:
    void getPermutation(vector<vector<int>>& ret, vector<int>& vec, vector<int>& nums, vector<int>& visited){
        if(vec.size() == nums.size()){
            ret.push_back(vec);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                vec.push_back(nums[i]);
                visited[i] = 1;
                getPermutation(ret, vec, nums, visited);
                visited[i] = 0;
                vec.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        vector<int> visited(nums.size(), 0);
        getPermutation(ret, vec, nums, visited);
        return ret;
    }
};