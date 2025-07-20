class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> arr1(26, 0), arr2(26, 0);

        for(char c : s1){
            arr1[c-'a']++;
        }

        for(int i = 0; i < s1.length(); i++){
            arr2[s2[i]-'a']++;
        }


        if(arr1 == arr2) return true;


        int range = s1.length();
        for(int i = range; i < s2.length(); i++){
            arr2[s2[i]-'a']++;
            arr2[s2[i-range]-'a']--;
            if(arr1 == arr2) return true;
        }

        return false;
    }
};