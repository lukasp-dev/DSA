class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char c : s){
            if(isspace(c) || !isalnum(c)) continue;
            str += tolower(c);
        }

        string tmp = str;
        reverse(str.begin(), str.end());

        return tmp == str;
    }
};