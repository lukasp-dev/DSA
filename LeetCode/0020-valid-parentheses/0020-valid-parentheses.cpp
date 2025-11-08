class Solution {
public:
    stack<char> stk;
    map<char, char> mp = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    bool isValid(string s) {
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                stk.push(c);
            }else{
                if(!stk.empty() && stk.top() == mp[c]){
                    stk.pop();
                }else{
                    stk.push(c);
                }
            }
        }

        return stk.empty();
    }
};