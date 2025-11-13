class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;
        int prefix = 0, cnt = 0;
        

        for(int num : nums){
            prefix += num;
            int complement = prefix - k;
            if(prefixMap.count(complement)){
                cnt += prefixMap[complement];
            }
            prefixMap[prefix]++;
        }

        return cnt;
    }
};