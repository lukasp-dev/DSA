class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> smaller;

        for (int i = 0; i < sorted.size(); i++) {
            if (!smaller.count(sorted[i])) {
                smaller[sorted[i]] = i;
            }
        }

        vector<int> ans;
        for (int num : nums) {
            ans.push_back(smaller[num]);
        }

        return ans;
    }
};