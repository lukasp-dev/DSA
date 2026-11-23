class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> lookup;

        for(int num : nums) {
            if(lookup.find(num) == lookup.end()) {
                ++lookup[num];
            } else {
                return true;
            }
        }

        return false;
    }
};