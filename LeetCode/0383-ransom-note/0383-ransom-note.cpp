class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> map1;
        map<char, int> map2;
        
        for(char& c : ransomNote){
            map1[c]++;
        }

        for(char& c : magazine) {
            map2[c]++;
        }

        for(char& c : ransomNote) {
            if(map2.count(c) == 0) return false;
            if(map1[c]>map2[c]) return false;
        }

        return true;
    }
};