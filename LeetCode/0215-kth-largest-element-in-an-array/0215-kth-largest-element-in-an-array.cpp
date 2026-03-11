class Solution {
public:
    struct cmp {
        bool operator()(const int& a , const int& b){
            return a < b;
        }
    };

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        
        for(int num : nums){
            pq.push(num);
        }
    
        for(int i=0; i<k-1; i++){
            pq.pop();
        }

        return pq.top();
    }
};