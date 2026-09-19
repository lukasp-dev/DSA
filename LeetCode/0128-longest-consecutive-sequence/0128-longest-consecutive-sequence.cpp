class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> _set(nums.begin(), nums.end());
        int longest = 0;

        for(int num : _set) {
            if(!_set.count(num-1)){
                int copy = num;
                int currLen = 0;
                while(_set.count(copy)){
                    currLen++;
                    copy++;
                }

                longest = max(longest, currLen);
            }
        }

        return longest;
    }
};