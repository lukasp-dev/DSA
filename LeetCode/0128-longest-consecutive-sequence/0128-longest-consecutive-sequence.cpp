class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup(nums.begin(), nums.end());
        int longest = 0;
        
        for(int num : lookup){
            int curr = num;
            if(lookup.find(curr-1) == lookup.end()){ //the initial point of a sequence
                int streak = 1;
                while(lookup.find(curr+1) != lookup.end()){
                    streak++;
                    curr++;
                }
                longest = max(longest, streak);
            }
        }

        return longest;
    }
};