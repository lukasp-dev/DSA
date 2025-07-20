class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            auto it = find(nums.begin(), nums.begin()+i, complement);
            if(it == nums.end()) it = find(nums.begin()+i+1, nums.end(), complement);
            int dist = distance(nums.begin(), it);
            if(it != nums.end() && dist != i){
                return {i, dist};
            }
        }
        return {};
    }
};