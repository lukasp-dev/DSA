class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(string str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            groups[copy].push_back(str);
        }

        vector<vector<string>> ret;
        for(const auto& it : groups) {
            ret.push_back(it.second);
        }

        return ret;
    }
};

