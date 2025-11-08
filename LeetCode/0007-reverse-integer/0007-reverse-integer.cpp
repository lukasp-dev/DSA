class Solution {
public:
    int reverse(int x) {
        bool isPositive = false;
        if(x>0) isPositive = true;
        string temp = to_string(abs((long long)x));
        int l = 0, r = temp.size()-1;
        while(l<r){
            swap(temp[l], temp[r]);
            l++;r--;
        }

        long long v = stoll(temp);
        if (!isPositive) v = -v;

        if (v > INT_MAX || v < INT_MIN) return 0;
        return (int)v;
    }
};