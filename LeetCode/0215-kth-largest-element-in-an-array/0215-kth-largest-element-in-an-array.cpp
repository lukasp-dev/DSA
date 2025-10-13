class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        struct cmp{
            bool operator()(const int& a, const int& b)const{
                return a < b;
            }
        };
        
        priority_queue<int, vector<int>, cmp> pq;
        
        for(int num : nums)pq.push(num);

        int ret = pq.top();

        while(k != 0){
            ret = pq.top(); pq.pop(); 
            k--;
        }

        return ret;
    }
};