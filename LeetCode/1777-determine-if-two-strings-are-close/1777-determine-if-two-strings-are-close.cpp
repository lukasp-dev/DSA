class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> set1; set<char> set2;
        unordered_map<char, int> mp1; unordered_map<char, int> mp2;

        for(char c : word1){
            set1.insert(c);
            mp1[c]++;
        }

        for(char c : word2){
            set2.insert(c);
            mp2[c]++;
        }

        if(set1 != set2) return false;

        vector<int> freq1, freq2;
        for (auto [c, cnt] : mp1) freq1.push_back(cnt);
        for (auto [c, cnt] : mp2) freq2.push_back(cnt);

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

// 1. we have the same set of alphabets
// 2. we have the same set of occurrence of each number (but doesn't have to be the same alphabet)