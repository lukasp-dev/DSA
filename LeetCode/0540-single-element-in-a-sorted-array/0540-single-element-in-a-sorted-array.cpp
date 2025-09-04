class Solution {
public:
    int recursiveFind(vector<int>& nums, int l, int r){
        if(l==r) return nums[l];

        int mid = l + (r-l)/2;
        
        bool leftSame = (mid-1 >= l) && (nums[mid-1] == nums[mid]);
        bool rightSame = (mid+1 <= r) && (nums[mid+1] == nums[mid]);

        if(leftSame){
            if ((mid - l + 1) % 2 == 0) {
                return recursiveFind(nums, mid + 1, r);
            } else {
                return recursiveFind(nums, l, mid - 2);
            }
        }else if (rightSame) {
            if ((r - mid + 1) % 2 == 0) {
                return recursiveFind(nums, l, mid - 1);
            } else {
                return recursiveFind(nums, mid + 2, r);
            }
        } else{
            return nums[mid];
        }
    }

    int singleNonDuplicate(vector<int>& nums) {
        return recursiveFind(nums, 0, nums.size()-1);
    }
};