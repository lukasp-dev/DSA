class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup(nums.begin(), nums.end());
        int longest = 0;

        for(int num : lookup){
            int curr = num;
            if(!lookup.count(num-1)){
                int streak = 1;
                while(lookup.count(curr+1)){
                    curr++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }

        return longest;
    }
};