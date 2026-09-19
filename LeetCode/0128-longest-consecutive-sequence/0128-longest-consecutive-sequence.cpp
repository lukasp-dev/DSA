class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());

        int longest = 1;
        int currLen = 1;

        for(int i=0; i<n-1; ++i) {
            if(nums[i] == nums[i+1]) continue;
            if(nums[i+1] == nums[i]+1) {
                currLen += 1;
                longest = max(longest,currLen);
            } else {
                currLen = 1;
            }
        }

        return longest;
    }
};