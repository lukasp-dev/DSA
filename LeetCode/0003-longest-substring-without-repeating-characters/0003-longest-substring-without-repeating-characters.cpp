class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;

        unordered_map<int, int> indices; // 문자가 마지막에 나온 indices 를 적는다

        int start = 0;
        int maxLen = 1;
        indices[s[0]] = 0;

        for(int i=1; i<n; i++) {
            if(indices.find(s[i]) != indices.end()) {
                start = max(start, indices[s[i]] + 1);
            }
            
            indices[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};