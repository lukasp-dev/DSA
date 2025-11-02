class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        int index = 0;

        for(auto it : freq){
            int times = it.second;
            for(int i=0; i<times; i++){
                nums[index] = it.first;
                index++;
            }
        }
    }
};