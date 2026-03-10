class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0;
        int ret = -1;
        int l = 0, r = 0;
        
        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }

            ret = max(ret, r-l+1);
            r++;
        }


        return ret;
    }
};