class Solution {
public:
    string removeDuplicates(string s) {
        string str;

        for(char& c : s) {
            if(!str.empty()) {
                if(str[str.size()-1] == c) {
                    str.pop_back();
                } else {
                    str.push_back(c);
                }
            } else {
                str.push_back(c);
            }
        }

        return str;
    }
};