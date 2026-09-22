class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr = accumulate(nums.begin(), nums.begin() + k, 0);
        double _max = curr;

        int l = 0, r = k;

        while(r < nums.size()){
            curr -= nums[l];
            curr += nums[r];
            _max = max(_max, curr);
            l++;
            r++;
        }

        return _max/k;
    }
};