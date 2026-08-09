class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        int r = 0;

        for(; r < t.size(); r++){
            if(s[l] == t[r]){
                cout << s[l] << "\n";
                l++;
            }
        }

        return l == s.size();
    }
};