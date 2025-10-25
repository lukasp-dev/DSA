class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> lastIndex;
        int startIndex = 0;
        int longest = 0;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            
            if(lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= startIndex){
                startIndex = lastIndex[c] + 1;
            }

            lastIndex[c] = i;
            longest = max(longest, i - startIndex + 1);
        }

        return longest;
    }
};