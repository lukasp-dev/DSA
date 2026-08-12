class Solution {
private:
    struct cmp {
        bool operator()(const int& a, const int& b) {
            return a > b;
        }
    };

public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> minHeap;

        for(int num : nums) {
            minHeap.push(num);
            if(minHeap.size() > k) minHeap.pop();
        }        

        return minHeap.top();
    }
};