class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = 1e9;
        int l=0, r=0;
        int rangeSum = 0;

        while(l<=r && r<nums.size()) {
            rangeSum += nums[r];

            while(rangeSum >= target){
                ret = min(ret, r-l+1);
                rangeSum -= nums[l++];
            }

            r++;
        }

        return ret == 1e9 ?  0 : ret;
    }
};