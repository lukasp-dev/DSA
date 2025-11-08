class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; 

        string str = to_string(x);
        int l=0, r=str.size()-1;

        while(l<r){
            if(str[l] == str[r]){
                l++;r--;
            }else{
                return false;
            }
        }

        return true;
    }
};