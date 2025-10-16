class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubSum = 0;
        int maxSum = INT_MIN;

        for(int num : nums){
            maxSubSum += num; 

            if(maxSubSum < num){
                maxSubSum = num;
            }

            maxSum = max(maxSum, maxSubSum);
        }

        return maxSum;
    }
};