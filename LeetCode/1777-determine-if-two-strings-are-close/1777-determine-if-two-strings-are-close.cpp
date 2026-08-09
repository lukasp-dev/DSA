class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        unordered_set<int> lookup(word1.begin(), word1.end());
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for(char c: word1) {
            freq1[c -'a']++;
        }

        for(char c : word2) {
            if(lookup.count(c) == 0) return false;
            freq2[c-'a']++;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};