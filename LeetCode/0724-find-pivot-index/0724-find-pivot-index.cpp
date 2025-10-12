class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 0;
        }

        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        int prefix = 0;
        for(int i=0; i<n; i++){
            int curr = nums[i];
            int cmp = totalSum - curr - prefix;

            if(prefix == cmp){
                return i;
            }

            prefix+=curr;
        }

        return -1;
    }
};