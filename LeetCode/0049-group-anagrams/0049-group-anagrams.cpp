class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1) return {strs};
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> um;

        for(string str : strs){
            string tmp = str;
            sort(str.begin(), str.end());
            um[str].push_back(tmp);
        }

        for(auto it : um){
            ret.push_back(it.second);
        }

        return ret;
    }
};