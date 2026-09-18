class Solution {
private:
    void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if(left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, temp, left, mid);
        mergeSort(nums, temp, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int k = left;

        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while(i <= mid)
            temp[k++] = nums[i++];

        while(j <= right)
            temp[k++] = nums[j++];

        for(int x = left; x <= right; x++)
            nums[x] = temp[x];
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());

        mergeSort(nums, temp, 0, nums.size() - 1);

        return nums;
    }
};