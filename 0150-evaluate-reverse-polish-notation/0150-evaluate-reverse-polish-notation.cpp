class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1){
            return stoi(tokens[0]);
        }

        stack<int> stk;
       
        for(string str : tokens){
            if(str == "+" || str == "-" || str == "/" || str == "*"){
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                if(str == "+"){
                    stk.push(a+b);
                }else if(str == "-"){
                    stk.push(a-b);
                }else if(str == "*"){
                    stk.push(a*b);
                }else if(str == "/"){
                    stk.push(a/b);
                }
            }else{
                stk.push(stoi(str));
            }
        }

        return stk.top();
    }
};