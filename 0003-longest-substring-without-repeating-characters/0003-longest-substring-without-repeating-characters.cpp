class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxLen = 0;
        set<char> seen;

        while(r < s.size()){
            if(seen.find(s[r]) != seen.end()){
                seen.erase(s[l]);
                l++;
            }else{
                seen.insert(s[r]);
                maxLen = max(maxLen, r-l+1);
                r++;
            }
        }

        return maxLen;
    }
};