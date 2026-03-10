class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        
        bool isFirst = true;
        string str = "";

        for(int i=0; i<s.size(); i++){
            char curr = s[i];
            if(isspace(curr) && isFirst) continue;
            else if(!isspace(curr)){
                isFirst = false;
                str.push_back(curr);
            }else if(isspace(curr) && !isFirst){
                stk.push(str);
                str = ""; 
                isFirst = true;
            }
        }

        if(!str.empty())stk.push(str);

        string ret = "";

        while(!stk.empty()){
            ret += stk.top();
            stk.pop();
            if(!stk.empty())ret += " ";
        }

        return ret;
    }
};