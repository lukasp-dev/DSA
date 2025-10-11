class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[l] == 0 && nums[i] != 0){
                swap(nums[l], nums[i]);
                l++;
            }

            if(nums[l] != 0) l++;
        }
    }
};