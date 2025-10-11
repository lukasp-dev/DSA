class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0, r = 0;
        int n = s.size(), m = t.size();

        while(l<n && r<m){
            if(s[l] == t[r]){
                l++; r++;
            }else{
                r++;
            }
        }

        return l == n;
    }
};