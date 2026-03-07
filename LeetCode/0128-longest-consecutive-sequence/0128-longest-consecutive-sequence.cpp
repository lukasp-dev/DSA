class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;

        int _max = 1;
        sort(nums.begin(), nums.end());
        
        int len = 1;
        int prev = nums[0];
        
        for(int i=1; i<n; i++){
            int curr = nums[i];
            if(curr == prev) continue;
            if(curr == prev+1){
                len++;
                _max = max(len, _max);
            }else len = 1;
            prev = curr;
        }

        return _max;
    }
};