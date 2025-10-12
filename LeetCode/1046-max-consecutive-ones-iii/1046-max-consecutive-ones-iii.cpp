class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1){
            return k ? 1:0;
        }

        int l=0, r=0;
        int zeros = 0;
        int greatest = 0;

        while(r < n){
            if(nums[r] == 0) zeros++;

            if(zeros > k){
                if(nums[l++]==0) zeros--;
            }else{
                greatest = max(greatest, r-l+1);
            }
            r++;
        }

        return greatest;
    }
};