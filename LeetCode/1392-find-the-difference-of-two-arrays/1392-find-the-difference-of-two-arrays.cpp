class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer;
        unordered_set<int> set1, set2;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for(int el : nums1) set1.insert(el);
        for(int el : nums2) set2.insert(el);

        vector<int> first;
        vector<int> second;

        for(int i = 0; i < nums1.size(); ++i) {
            if(i != nums1.size()-1 && nums1[i] == nums1[i+1]) continue;
            
            if(set2.find(nums1[i]) == set2.end()) {
                first.push_back(nums1[i]);
            }
        }

        for(int i = 0; i < nums2.size(); ++i) {
            if(i != nums2.size()-1 && nums2[i] == nums2[i+1]) continue;
            
            if(set1.find(nums2[i]) == set1.end()) {
                second.push_back(nums2[i]);
            }
        }

        answer.push_back(first);
        answer.push_back(second);

        return answer;
    }
};