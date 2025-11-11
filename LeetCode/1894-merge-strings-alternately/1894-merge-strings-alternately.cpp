class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.size() == 0) return word2;
        if(word2.size() == 0) return word1;

        int n = word1.size(); int m = word2.size();
        string res = "";
        int i;
        for(i=0; i<min(n, m); i++){
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }

        while(i < n){
            res.push_back(word1[i]);
            i++;
        }
        while(i < m){
            res.push_back(word2[i]);
            i++;
        }

        return res;
    }
};