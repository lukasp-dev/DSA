class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> pair1;

        pair1['('] = ')';
        pair1['{'] = '}';
        pair1['['] = ']';

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(!stk.empty() && pair1.find(ch) == pair1.end() && pair1[stk.top()] == ch){
                stk.pop();
            } else {
                stk.push(ch);
            }
        }

        return stk.size() == 0;
    }
};