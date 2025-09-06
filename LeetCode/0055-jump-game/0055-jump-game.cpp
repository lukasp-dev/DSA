class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i=0; i<nums.size(); i++){
            if(maxReach < i){
                return false;
            }

            maxReach = max(maxReach, nums[i] + i);
        }

        return true;
    }
};
//  0, 1, 2, 3, 4
// [2, 3, 1, 1, 4]
// [2, 4, 3, 4, 8]

// [3, 2, 1, 0, 4]
// [3, 3, 3, 3, 8]