class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        
        for(int i=0; i<n-2; ++i) {
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            
            if (nums[i] > 0) {
                break;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0){
                    --right;
                } else if(sum < 0){
                    ++left;
                } else {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    ++left; --right;

                    while(left < right && nums[left-1] == nums[left]) ++left;
                    while(left < right && nums[right+1] == nums[right]) --right;
                }
            }
        }

        return ret;
    }
};