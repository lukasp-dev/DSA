class Solution {
private:
    bool isAllMatch(vector<string>& strs, char& c, int idx) {
        for(string& str : strs) {
            if(str[idx] != c) return false;
        }
        return true;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        int minSize = strs[0].size();
        string* minStr = &strs[0];

        for(string& str : strs) {
            if(str.size() < minSize) {
                minSize = str.size();
                minStr = &str;
            }
        }

        string ans;

        for(int i=0; i < minStr->size(); ++i) {
            if(isAllMatch(strs, (*minStr)[i], i)){
                ans += (*minStr)[i];
            } else {
                return ans;
            }
        }

        return ans;
    }
};