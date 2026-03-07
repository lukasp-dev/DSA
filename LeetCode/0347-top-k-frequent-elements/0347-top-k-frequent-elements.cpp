class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n : nums) freq[n]++;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

        for(auto& it : freq){
            pq.push(it);
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> ret;

        while(!pq.empty()){
            auto it = pq.top();
            ret.push_back(it.first);
            pq.pop();
        }

        return ret;
    }
};