class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        stack<string> stk;
        while(i<s.size()){
            while(isspace(s[i])){
                i++;
            }
            string str = "";
            while(isalnum(s[i])){
                str.push_back(s[i]);
                i++;
            }
            if(str.size() > 0) stk.push(str);
        }

        string res;
        bool isFirst = true;
        while(!stk.empty()){
            string top = stk.top(); stk.pop();
            if(!isFirst){
                res += (" " + top);
            }else{
                res += top;
            }
            isFirst = false;
        }

        return res;
    }
};