class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for(char c : word1){
            freq1[c]++;
        }
        for(char c : word2){
            if(!freq1.count(c)) return false;
            freq2[c]++;
        }
        
        unordered_map<int, int> map1, map2;
        for(auto [_, freq] : freq1) map1[freq]++;
        for(auto [_, freq] : freq2) map2[freq]++;
        return map1 == map2;
    }
};