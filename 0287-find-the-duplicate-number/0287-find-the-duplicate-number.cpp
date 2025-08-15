class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx = nums[0];
        int nextIdx;
        
        while(nums[idx] != 0){
            nextIdx = nums[idx];
            nums[idx] = 0;
            idx = nextIdx;
        }

        return idx;
    }
};