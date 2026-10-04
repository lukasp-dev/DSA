class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(char& c : s) {
            if(stk.empty()){
                stk.push(c);
            } else {
                if(stk.top() == '('){
                    if(c == ')'){
                        stk.pop();
                        continue;
                    }
                } else if(stk.top() == '{') {
                    if(c == '}'){
                        stk.pop();
                        continue;
                    }
                } else if(stk.top() == '[') {
                    if(c == ']'){
                        stk.pop();
                        continue;
                    }
                }

                stk.push(c);
            }
        }


        return stk.empty();
    }
};