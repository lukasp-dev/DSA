class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int _max = 1;
        int len = 1;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] + 1 == nums[i+1]){
                len++;
                _max = max(_max, len);
            }else{
                len = 1;
            }
        }

        return _max;
    }
};