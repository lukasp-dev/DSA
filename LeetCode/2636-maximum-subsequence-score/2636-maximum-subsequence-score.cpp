class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)const{
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first; 
        }
    };

    struct cmp1{
        bool operator()(const int& a, const int& b){
            return a > b;
        }
    };

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int, int>> pairs;

        for(int i=0; i<n; i++){
            pairs.push_back({nums2[i], nums1[i]});
        }

        sort(pairs.begin(), pairs.end(), cmp());

        priority_queue<int, vector<int>, cmp1> pq;

        long long ans = 0, sum=0;

        for(auto [b, a] : pairs){
            pq.push(a);
            sum += a;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                ans = max(ans, sum*b);
            }
        }

        return ans;
    }
};