class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(char ch : magazine){
            mp1[ch]++;
        }

        for(char ch : ransomNote){
            mp2[ch]++;
        }

        for(auto& [ch, num] : mp2){
            if(mp1.find(ch) == mp1.end()) return false;
            if(mp1[ch] >= num) continue;
            else return false;
        }
        return true;
    }
};