class Solution {
public:
    struct cmp{
        bool operator()(const int& a, const int& b)const{
            return a > b;
        }
    };

    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int l = 0, r = n-1;

        priority_queue<int, vector<int>, cmp> lowerPq;
        priority_queue<int, vector<int>, cmp> higherPq;

        for (int i = 0; i < candidates && l <= r; i++) lowerPq.push(costs[l++]);
        for (int i = 0; i < candidates && l <= r; i++) higherPq.push(costs[r--]);


        long long ans = 0;

        while(k != 0){
            int lowerCandidate = lowerPq.empty() ? INT_MAX : lowerPq.top();
            int higherCandidate = higherPq.empty() ? INT_MAX : higherPq.top();

            if(!lowerPq.empty()){
                cout << "curr low: " << lowerPq.top() << "\n";;
                lowerCandidate = lowerPq.top();
            }

            if(!higherPq.empty()){
                cout << "curr high: " << higherPq.top() << "\n";
                higherCandidate = higherPq.top();
            }

            if(lowerCandidate == higherCandidate || lowerCandidate < higherCandidate){
                ans += lowerCandidate;
                lowerPq.pop();
                if (l <= r) lowerPq.push(costs[l++]);
            }else{
                ans += higherCandidate;
                higherPq.pop();
                if (l <= r) higherPq.push(costs[r--]);
            }

            k--;
        }

        return ans;
    }
};