class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(26, 0), arr2(26, 0);

        for(char c : s){
            arr1[c-'a']++;
        }

        for(char c : t){
            arr2[c-'a']++;
        }

        return arr1 == arr2;
    }
};