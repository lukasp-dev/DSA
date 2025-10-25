class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;

        for(int i=0; i<nums.size(); i++){
            lookup[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            auto it = lookup.find(complement);
            if(it != lookup.end() && it->second != i){
                return {lookup[complement], i};
            }
        }

        return {};
    }
};