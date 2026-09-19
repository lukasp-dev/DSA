class Solution {
private:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second > b.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        for(int num : nums) freq[num]++;

        vector<pair<int, int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), cmp());

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};