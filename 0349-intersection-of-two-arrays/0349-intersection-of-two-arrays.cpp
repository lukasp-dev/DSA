class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_set<int> st;

        for(int num : nums1){
            if(st.find(num) == st.end() && find(nums2.begin(), nums2.end(), num) != nums2.end()){
                auto it = find(nums2.begin(), nums2.end(), num);
                ret.push_back(*it);
                st.insert(*it);
            }
        }

        return ret;
    }
};