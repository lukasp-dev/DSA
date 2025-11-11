class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int prefix = 0;

        for(int i=0; i<nums.size(); i++){
            int curr = sum - prefix - nums[i];
            if(curr == prefix){
                return i;
            }
            prefix += nums[i];
        }

        return -1;
    }
};