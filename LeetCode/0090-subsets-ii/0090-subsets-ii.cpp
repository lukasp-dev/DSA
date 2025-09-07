class Solution {
public:
    void makeSubsets(vector<vector<int>>& ret, vector<int>& nums, vector<int>& vec, int start){
        ret.push_back(vec);
        
        for(int i=start; i<nums.size(); i++){
            if (i > start && nums[i] == nums[i-1]) continue;
            vec.push_back(nums[i]);
            makeSubsets(ret, nums, vec, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> vec;
        makeSubsets(ret, nums, vec, 0);

        return ret;
    }
};