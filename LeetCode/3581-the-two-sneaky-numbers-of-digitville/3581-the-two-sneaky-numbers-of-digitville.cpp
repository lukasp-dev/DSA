class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> lookup;
        vector<int> res;
        
        for(int num : nums){
            lookup[num]++;
        }

        for(auto it : lookup){
            if(it.second == 2){
                res.push_back(it.first);
            }
        }

        return res;
    }
};