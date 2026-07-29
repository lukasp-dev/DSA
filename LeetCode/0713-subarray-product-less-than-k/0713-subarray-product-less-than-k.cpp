class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int ret = 0;
        int l = 0, r = 0;
        long long rangeProduct = 1;

        for(; r < nums.size(); r++) {
            rangeProduct *= nums[r];

            while(rangeProduct >= k){
                rangeProduct /= nums[l];
                l++;
            }

            ret += r - l + 1;
        }

        return ret;
    }
};