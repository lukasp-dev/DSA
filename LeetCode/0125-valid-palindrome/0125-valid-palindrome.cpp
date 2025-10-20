class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        
        while(l<=r){
            char left = s[l];
            char right = s[r];

            if(!isalnum(left)){
                l++;
                continue;
            }
            if(!isalnum(right)){
                r--;
                continue;
            }
                    
            if(tolower(left) != tolower(right)){
                return false;
            }
            l++;r--;
        }
        return true;
    }
};