class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(n==2) return nums[0] > nums[1] ? 0:1;

        int l=0, r=n-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            int left = (mid <= 0) ?  INT_MIN : nums[mid - 1];
            int right = (mid >= n-1) ? INT_MIN : nums[mid + 1];

            int curr = nums[mid];

            if(left<curr && curr>right) return mid;

            if(left>=right) r = mid-1;
            else l = mid+1;
        }

        return -1;
    }
};