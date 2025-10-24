class Solution {
public:
    unordered_map<char, char> lookup = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    bool isValid(string s) {
        stack<char> stk;

        for(char c : s){
            if(c == '(' || c == '{' || c=='['){
                stk.push(c);
            }else {
                if (!stk.empty() && lookup[c] == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};