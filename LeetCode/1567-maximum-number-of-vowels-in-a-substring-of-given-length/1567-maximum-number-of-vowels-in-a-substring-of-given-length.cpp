class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e'|| c == 'i'||c == 'o'||c == 'u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int iStringNum = 0;

        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                iStringNum++;
            }
        }

        if(s.size() == k){
            return iStringNum;
        }

        int greatest = iStringNum;

        for(int r = k; r < s.size(); r++){
            bool isLeftVowel = isVowel(s[r-k]);
            bool isRightVowel = isVowel(s[r]);

            if(isLeftVowel) iStringNum--;
            if(isRightVowel) iStringNum++;

            greatest = max(greatest, iStringNum);
        }

        return greatest;
    }
};