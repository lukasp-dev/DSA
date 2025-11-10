class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int op2= stk.top(); stk.pop();
                int op1= stk.top(); stk.pop();

                if(token == "+"){
                    stk.push(op1+op2);                         
                }else if(token == "-"){
                    stk.push(op1-op2);
                }else if(token == "*"){
                    stk.push(op1*op2);
                }else if(token == "/"){
                    stk.push(op1/op2);
                }
            }else{
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};