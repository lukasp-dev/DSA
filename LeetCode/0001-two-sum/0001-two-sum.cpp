class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        
        for(int i=0; i<nums.size(); i++){
            indices[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];

            if(indices.find(complement) != indices.end() && i != indices[complement]){
                return {i, indices[complement]};
            }
        }

        return {};
    }
};