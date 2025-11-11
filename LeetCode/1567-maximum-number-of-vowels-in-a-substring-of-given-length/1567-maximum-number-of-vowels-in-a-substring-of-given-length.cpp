class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int vowelCount = 0;
        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                vowelCount++;
            }
        }

        int res = vowelCount;

        int n=s.size(), l=0;
        for(int r=k; r<n; r++){
            if(isVowel(s[l])){
                vowelCount--;
            }
            if(isVowel(s[r])){
                vowelCount++;
            }
            res = max(res, vowelCount);
            l++;
        }

        return res;
    }
};