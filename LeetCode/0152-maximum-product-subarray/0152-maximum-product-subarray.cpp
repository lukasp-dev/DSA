class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minSub = 1;
        int maxSub = 1;
        int res = nums[0];

        for(int num : nums){
            if (num < 0){
                swap(minSub, maxSub);
            }

            minSub = min(minSub*num, num);
            maxSub = max(maxSub*num, num);

            res = max(res, maxSub);
        }

        return res;
    }
};