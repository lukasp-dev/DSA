class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        
        int k = 0;

        for(int i=0; i<nums.size(); i++) {
            if(!seen.count(nums[i])){
                nums[k++] = nums[i];
                seen.insert(nums[i]);
            }
        }

        return k;
    }
};