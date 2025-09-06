class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = INT_MIN;
        int ret;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto& it : mp){
            if(maxFreq < it.second){
                maxFreq = it.second;
                ret = it.first;
            }
        }

        return ret;
    }
};