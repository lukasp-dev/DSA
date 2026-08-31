class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        if (nums.size() == 2) {
            swap(nums[0], nums[1]);
            return;
        }

        int pivotIndex = nums.size()-2;

        while(pivotIndex >= 0) {
            if(nums[pivotIndex] < nums[pivotIndex+1]) break;
            --pivotIndex;
        }

        if(pivotIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int i = nums.size()-1;
        while(i > pivotIndex) {
            if(nums[i] > nums[pivotIndex]) {
                swap(nums[pivotIndex], nums[i]);
                break;
            }
            --i;
        }

        reverse(nums.begin() + pivotIndex + 1, nums.end());
    }
};