class Solution {
private:
    stack<string> stk;

public:
    int evalRPN(vector<string>& tokens) {
        for(string token : tokens) {

            if(token == "+" || token == "-" || token == "*" || token == "/") {
                string a = stk.top(); stk.pop();
                string b = stk.top(); stk.pop();
                int res;

                if(token == "+") {
                    res = stoi(a) + stoi(b);
                } else if(token == "-") {
                    res = stoi(b) - stoi(a);
                } else if(token == "*") {
                    res = stoi(a) * stoi(b);
                } else {
                    res = stoi(b) / stoi(a);
                }

                stk.push(to_string(res));
            } else {
                stk.push(token);
            }
        }

        cout << stk.size() << "\n";

        return stoi(stk.top());
    }
};