class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            auto it = lookup.find(nums[i]);
            if(it != lookup.end()) {
                if(abs(i - it->second) <= k) {
                    return true;
                }
            }

            lookup[nums[i]] = i;
        }

        return false;
    }
};