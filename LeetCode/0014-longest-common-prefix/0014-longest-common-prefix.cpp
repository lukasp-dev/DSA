class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int validIndex = strs[0].size();
        string cmp = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int commonCnt = 0;
            string curr = strs[i];

            for (int j = 0; j < min(curr.size(), cmp.size()); j++) {
                if (cmp[j] == curr[j]) {
                    commonCnt++;
                } else {
                    break;
                }
            }

            validIndex = min(validIndex, commonCnt);
            if (validIndex == 0) return "";
        }

        return cmp.substr(0, validIndex);
    }
};
