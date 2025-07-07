class Solution {
public:
    string toLowerCase(string s) {
        string ret;
        for(int i=0; i<s.size(); i++){
            ret += tolower(s[i]);
        }
        return ret;
    }
};