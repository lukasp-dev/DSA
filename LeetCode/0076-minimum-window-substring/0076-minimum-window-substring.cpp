class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int remaining = m;

        if (n < m) {
            return "";
        }

        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            char c = s[right];

            if (need[c] > 0) {
                remaining--;
            }

            need[c]--;

            while (remaining == 0) {
                // 현재 window가 valid
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char x = s[left];

                need[x]++;

                if (need[x] > 0) {
                    remaining++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};