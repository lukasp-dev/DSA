class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> um;
    
        for(string str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            um[tmp].push_back(str);
        }

        for(auto& it : um){
            ret.push_back(it.second);
        }

        return ret;
    }
};