class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        string str = "";

        int i = 0, j = 0;

        while(i<m || j<n){
            if(i < m){
                str.push_back(word1[i++]);
            }
            if(j < n){
                str.push_back(word2[j++]);
            }
        }

        return str;
    }
};