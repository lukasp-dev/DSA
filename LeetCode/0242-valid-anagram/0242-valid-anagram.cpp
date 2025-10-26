class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> lookup;

        for(char c : s){
            lookup[c]++; 
        }

        for(char c : t){
            lookup[c]--;
        }

        for(auto it : lookup){
            if(it.second != 0) return false;
        }

        return true;
    }
};