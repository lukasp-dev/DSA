class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const{
            return p1.second < p2.second;
        };
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> ret;

        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

        for(auto& it : um){
            pq.push(it);
        }

        for(int i=0; i<k; i++){
            auto it = pq.top();
            ret.push_back(it.first);
            pq.pop();
        }

        return ret;
    }
};