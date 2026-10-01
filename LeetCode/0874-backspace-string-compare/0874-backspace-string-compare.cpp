class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1, str2;

        for(char& c : s) {
            if(c == '#' && str1.size() != 0) {
                str1.pop_back();
                continue;
            }

            if(c == '#') continue;

            str1.push_back(c);
        }

        for(char& c : t) {
            if(c == '#' && str2.size() != 0) {
                str2.pop_back();
                continue;
            }

            if(c == '#') continue;

            str2.push_back(c);
        }

        cout << str1 << "\n";
        cout << str2 << "\n";

        return str1 == str2;
    }
};