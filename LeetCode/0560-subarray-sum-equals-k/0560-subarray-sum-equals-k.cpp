class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum = 0;
        int ret = 0;
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        for(int i=0; i<n; ++i) {
            prefixSum += nums[i];
            int complement = prefixSum - k;
            if(prefixCount.count(complement)) ret += prefixCount[complement];
            prefixCount[prefixSum]++;
        }

        return ret;
    }
};
