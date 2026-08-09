class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        int sum;
        int num = 0;

        while(l < r) {
            sum = nums[l] + nums[r];
            
            if(sum > k) {
                r--;
            } else if(sum < k) {
                l++;
            } else {
                num++;
                l++;r--;
            }
        }

        return num;
    }
};
