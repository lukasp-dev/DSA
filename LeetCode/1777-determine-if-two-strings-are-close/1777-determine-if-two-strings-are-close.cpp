class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> freq1, freq2;

        for(char c : word1){
            freq1[c]++;
        }

        for(char c : word2){
            if(freq1.find(c) == freq1.end()) return false;
            freq2[c]++;
        }

        map<char, int> mp1, mp2;
        for(auto it : freq1){
            mp1[it.second]++;
        }
        for(auto it : freq2){
            mp2[it.second]++;
        }

        return mp1 == mp2;
    }
};