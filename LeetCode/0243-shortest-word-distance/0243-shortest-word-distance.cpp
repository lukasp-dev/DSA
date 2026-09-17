class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        stack<pair<string, int>> stk;
        int _min = INT_MAX;

        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                if (!stk.empty() && stk.top().first == word2) {
                    _min = min(_min, abs(stk.top().second - i));
                }
                stk.push({wordsDict[i], i});
            }

            if (wordsDict[i] == word2) {
                if (!stk.empty() && stk.top().first == word1) {
                    _min = min(_min, abs(stk.top().second - i));
                }
                stk.push({wordsDict[i], i});
            }
        }

        return _min;
    }
};