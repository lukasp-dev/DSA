class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_map<int, int> occurrence;
        
        for(int num : arr){
            mp[num]++;
        }

        for(auto it : mp){
            occurrence[it.second]++;
        }

        for(auto it : occurrence){
            if(it.second > 1) return false;
        }

        return true;
    }
};