class Solution {
public:
    int reverse(int x) {
        bool isPositive = x > 0;
        long long n = llabs((long long)x);  // llabs가 더 선명

        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }

        if (rev > INT_MAX) return 0; 
        return isPositive ? (int)rev : -(int)rev;
    }
};
