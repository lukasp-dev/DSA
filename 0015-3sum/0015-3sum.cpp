class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() == 3){
            if(nums[0] + nums[1] + nums[2] == 0){
                return {{nums[0], nums[1], nums[2]}};
            } else{
                return {};
            }
        }

        const int TARGET = 0;
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());      

        for(int i=0; i<nums.size(); i++){

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int curr = nums[i];
            
            int l=i+1, r=nums.size()-1;
            
            while(l<r){
                int sum = nums[l] + nums[r] + curr;
                if(sum > TARGET){
                    r--;
                }else if(sum < TARGET){
                    l++;
                }else{
                    ret.push_back({nums[l], nums[r], curr});
                    l++;r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }

        return ret;
    }
};