class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i=0; i<n; i++) {
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 현재 값보다 작은 애들은 필요없음
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // window가 완성됐으면 max 기록 (valid 한 구간에서)
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            } 
        }

        return ans;
    }
};