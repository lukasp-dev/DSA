class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx = min(word1.length(), word2.length());

        string str = "";

        for(int i=0; i<idx; i++){
            str += word1[i];
            str += word2[i];
        }

        if(word1.end() - word1.begin() > idx){
            for(int i=idx; i<word1.length(); i++){
                str += word1[i];
            }
        }else{
            for(int i=idx; i<word2.length(); i++){
                str += word2[i];
            }
        }

        return str;
    }
};