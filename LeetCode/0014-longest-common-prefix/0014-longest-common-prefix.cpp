class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        string prefix = "";
        string first = strs[0];

        for(int i=0; i<first.size(); i++){
            char cmp = first[i];
            for(string str : strs){
                if(i >= str.size() || cmp != str[i]){
                    return prefix;
                }
            }
            prefix += cmp;
        }

        return prefix;
    }
};