class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int zeros = 0;
        int ret = 0;

        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }

            while(zeros > 1){
                if(nums[l] == 0) zeros--;
                l++;
            }

            ret = max(ret, r - l);
            r++;
        }

        return ret;
    }
};