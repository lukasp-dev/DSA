class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char,int> f1, f2;
        unordered_set<char> s1, s2;

        for (char c : word1) {
            f1[c]++;
            s1.insert(c);
        }
        for (char c : word2) {
            f2[c]++;
            s2.insert(c);
        }

        // (1) 같은 알파벳만 사용했는지 확인
        if (s1 != s2) return false;

        // (2) 빈도 분포가 같은지 확인
        unordered_map<int,int> cnt1, cnt2;
        for (auto [_, freq] : f1) cnt1[freq]++;
        for (auto [_, freq] : f2) cnt2[freq]++;

        return cnt1 == cnt2;
    }
};
