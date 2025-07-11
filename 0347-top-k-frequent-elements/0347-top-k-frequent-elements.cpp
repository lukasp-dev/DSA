class Solution {
public:
    map<int, int> mp;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;

        for(int num : nums){
            mp[num]++;
        }

        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });

        for(int i=0; i<k; i++){
            ret.push_back(vec[i].first);
        }

        return ret;
    }
};