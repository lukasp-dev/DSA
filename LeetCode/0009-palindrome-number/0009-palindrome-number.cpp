class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x % 10 == 0 && x != 0) return false;

        int copy = x;
        long long reversed = 0; 
        while(copy > 0){
            reversed = 10*reversed + copy%10;
            copy /= 10;
        }

        return reversed == x;
    }
};