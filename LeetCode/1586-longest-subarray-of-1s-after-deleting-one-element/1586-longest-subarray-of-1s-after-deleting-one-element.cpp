class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0, r=0;
        int n = nums.size();
        int cap=1, zeros=0;
        int longest = 0;
        
        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }
            if(zeros>cap){
                if(nums[l++] == 0){
                    zeros--;
                }
            }else{
                longest = max(longest, r-l);
            }
            r++;
        }
        return longest;
    }
};