class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> freq;

        for(char& c : s) {
            freq[c]++;
        }

        for(char& c : t) {
            freq[c]--;
        }

        for(auto& [k, v] : freq) {
            if(v != 0) return false;
        }

        return true;
    }
};