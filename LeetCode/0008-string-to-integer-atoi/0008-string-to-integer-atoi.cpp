class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool isPos = true;
        int ptr = 0;
        long long res = 0;

        if(n==0) return 0;
        while(ptr < s.size() && isspace(s[ptr])) ptr++;
        if(s[ptr] == '-' || s[ptr] == '+'){
            if(s[ptr] == '-') isPos = false;
            ptr++;
        }

        while(ptr < s.size() && isdigit(s[ptr])){
            res = res*10 + (s[ptr]-'0');
            if(res > INT_MAX){
                res = isPos ? INT_MAX : INT_MIN;
                break;
            }
            ptr++;
        }

        if(!isPos && res != INT_MIN) res = -res;

        return res;
    }
};