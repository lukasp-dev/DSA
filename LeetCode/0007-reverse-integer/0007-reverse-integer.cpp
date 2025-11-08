class Solution {
public:
    int reverse(int x) {
        bool isPositive = x > 0;
        x = abs((long long)x);
        
        long long reverse = 0;
        
        while(x > 0){
            reverse = reverse*10 + x%10;
            x /= 10;
        }
        
        if(reverse > INT_MAX || reverse < INT_MIN) return 0; 
        return isPositive ? (int)reverse : -1*(int)reverse;
    }
};