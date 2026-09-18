class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> ans;

        for(int it : nums1) set.insert(it);

        for(int it : nums2) {
            if(set.find(it) != set.end()) {
                ans.push_back(it);
                set.erase(it);
            }
        }

        return ans;
    }
};