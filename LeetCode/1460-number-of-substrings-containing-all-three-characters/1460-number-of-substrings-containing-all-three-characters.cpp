class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, r=0;
        vector<int> count(3, 0);
        int ret = 0;

        for(;r<s.size();++r){
            count[s[r] - 'a']++;

            while(count[0] &&
                count[1] &&
                count[2]){
                count[s[l] - 'a']--;
                l++;
            }

            ret += l;
        }

        return ret;
    }
};