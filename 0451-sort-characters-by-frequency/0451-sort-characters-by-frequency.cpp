class Solution {
public:
    struct cmp {
        bool operator()(const pair<char,int>& a, const pair<char,int>& b) const {
            if (a.second != b.second)  // 빈도 다르면
                return a.second > b.second; // 빈도 내림차순
            return a.first < b.first;  // 빈도 같으면 문자 오름차순
        }
    };

    string frequencySort(string s) {
        unordered_map<char, int> um;
        for (char c : s) {
            um[c]++;
        }

        vector<pair<char, int>> vec(um.begin(), um.end());
        sort(vec.begin(), vec.end(), cmp());

        string str;
        for (auto& [ch, freq] : vec) {
            str.append(freq, ch); // 같은 문자 freq 번 반복
        }

        return str;
    }
};
