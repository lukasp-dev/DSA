class Solution {
public:
    bool isPalindrome(string s) {
        string str1, str2;
        for(int i=0; i<s.size(); i++){
            char now = s[i];
            if(isalnum(now)) str1+= tolower(now);
        }
        str2 = str1;
        reverse(str1.begin(), str1.end());
        return str1 == str2;
    }
};