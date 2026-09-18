class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        vector<int> ans;

        for(int it : nums1) set.insert(it);

        for(int it : nums2) {
            if(set.find(it) != set.end()) {
                map[it]++;
            }
        }

        for(auto& it : map) {
            ans.push_back(it.first);
        }

        return ans;
    }
};