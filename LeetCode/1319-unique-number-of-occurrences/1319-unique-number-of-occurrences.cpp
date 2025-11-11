class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> lookup;
        unordered_set<int> freq;

        for(int num : arr){
            lookup[num]++;
        }

        for(auto it : lookup){
            int currFreq = it.second;
            if(!freq.count(currFreq)){
                freq.insert(currFreq);
            }else{
                return false;
            }
        }

        return true;
    }
};