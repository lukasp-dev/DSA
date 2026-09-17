class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ptr = 0;
        int counter = 0;
        int _max = 0;

        while(ptr != nums.size()) {
            if(nums[ptr] == 0) counter = 0;
            else{
                _max = max(_max, ++counter);
            }
            ptr++;
        }

        return _max;
    }
};