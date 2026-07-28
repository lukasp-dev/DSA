class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        sort(nums.begin(), nums.end());

        int maxLen = 1;
        int currLen = 1;

        for(int i=0; i<n-1; ++i) {
            if(nums[i] == nums[i+1]){
                continue;
            } else if(nums[i]+1 == nums[i+1]){
                ++currLen;
                maxLen = max(currLen, maxLen);
            } else currLen = 1;
        }

        return maxLen;
    }
};