class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> ans;

        for(string str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());

            groups[copy].push_back(str);
        }

        for(auto& [k, v] : groups) {
            ans.push_back(v);
        }

        return ans;
    }
};