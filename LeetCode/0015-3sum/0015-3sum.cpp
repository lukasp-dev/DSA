class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1, r = n-1;
            while(l < r){
                int curr = nums[i], left = nums[l], right = nums[r];
                int sum = curr + left + right;

                if(sum == 0){
                    res.push_back({curr, left, right});
                    l++; r--;
                    while(l<r && nums[l] == nums[l-1]) l++;
                    while(l<r && nums[r] == nums[r+1]) r--;
                }else if(sum < 0){
                    l++;
                }else if(sum > 0){
                    r--;
                }
            }
        }

        return res;
    }
};
