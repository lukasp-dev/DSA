class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1){
            return k ? 1:0;
        }

        int l = 0, r = 0;
        int zeros = 0;  // 현재 윈도우 안의 0 개수
        int greatest = 0;

        // ✅ 윈도우 확장
        while (r < n) {
            if (nums[r] == 0) zeros++;

            // 0의 개수가 k 초과하면 왼쪽 포인터 이동
            while (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }

            greatest = max(greatest, r - l + 1);
            r++;
        }

        return greatest;
    }
};
