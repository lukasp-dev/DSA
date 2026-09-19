class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 

        for(int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        
        for(auto& [k, v] : freq) {
            bucket[v].push_back(k);
        }

        vector<int> ans;
        for(int i = bucket.size()-1; i >= 1; --i) {
            for(int num : bucket[i]) {
                ans.push_back(num);
                
                if(ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;

        return ans;
    }
};