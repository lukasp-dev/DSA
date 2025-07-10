class Solution {
public:

    void getPermutation(vector<vector<int>>& ret, int N, vector<bool>& used, vector<int>& vec, vector<int>& nums){
        if(vec.size() == N){
            ret.push_back(vec);
        }

        for(int i = 0; i<N; i++){
            if(!used[i]){
                used[i] = true;
                vec.push_back(nums[i]);
                getPermutation(ret, N, used, vec, nums);
                vec.pop_back();
                used[i] = false;
            }
        }
    }
    

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int N = nums.size();
        vector<int> vec;
        vector<bool> used(N, false);

        getPermutation(ret, N, used, vec, nums);

        return ret;
    }
};