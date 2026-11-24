class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> lookup;
        lookup[0] = -1;  // nums[0]을 더하기 전의 누적합

        long long prefix = 0;
        int max_len = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];

            auto it = lookup.find(prefix - k);
            if (it != lookup.end()) {
                max_len = max(max_len, i - it->second);
            }

            // 키가 없으면 넣고, 있으면 기존 값을 유지 (emplace)
            lookup.emplace(prefix, i);  // 이미 있으면 최초 인덱스 유지
        }

        return max_len;
    }
};