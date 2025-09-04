class Solution {
public:
    int recursiveFind(vector<int>& nums, int l, int u) {
        if (l == u) return l;

        int mid = l + (u - l) / 2;

        if ((mid == 0 || nums[mid] > nums[mid-1]) &&
            (mid == nums.size()-1 || nums[mid] > nums[mid+1])) {
            return mid;
        }

        if (mid > 0 && nums[mid-1] > nums[mid]) {
            return recursiveFind(nums, l, mid-1);
        }

        return recursiveFind(nums, mid+1, u);
    }

    int findPeakElement(vector<int>& nums) {
        return recursiveFind(nums, 0, nums.size()-1);
    }
};
