class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int prefix = 0;
        int count = 0;
        
        for(int num : nums){
            prefix += num;
            int complement = prefix - k;
            if(prefixCount.find(complement) != prefixCount.end()){
                count += prefixCount[complement];
            }
            prefixCount[prefix]++;
        }

        return count;
    }
};