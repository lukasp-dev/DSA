class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n-1;
        int k = n-1;

        vector<int> results(n);
        
        while(left <= right) {
            if(abs(nums[right]) >= abs(nums[left])) {
                results[k] = nums[right]*nums[right];
                right--;
            }else {
                results[k] = nums[left]*nums[left];
                left++;
            }
            k--;
        }

        return results;
    }
};