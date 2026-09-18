class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> _set;

        for(int it : nums) {
            if(_set.count(it) > 0) return true;
            _set.insert(it);
        }

        return false;
    }
};