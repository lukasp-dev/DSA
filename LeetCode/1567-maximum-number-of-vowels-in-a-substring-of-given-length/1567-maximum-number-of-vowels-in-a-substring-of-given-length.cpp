class Solution {
public:
    bool isVowel(char c){
        char tmp = tolower(c);
        set<char> cmp= {'a','e', 'i', 'o', 'u'};
        if(cmp.find(tmp) != cmp.end()){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int ret = 0, numVowel = 0;
        int l;
        int n = s.size();

        for(l=0; l<k; l++){
            if(isVowel(s[l])) {
                ret++;
                numVowel++;
            }
        }

        if(n == l+1) return ret;

        int r = k;

        while(r < n){
            if(isVowel(s[r-k])) numVowel--;
            if(isVowel(s[r])) numVowel++;
            cout << numVowel << "\n";
            ret = max(ret, numVowel);
            r++;
        }

        return ret;
    }
};