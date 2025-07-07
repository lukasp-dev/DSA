class Solution {
public:
    int check(string& sentence){
        int ret = 0;
        for(int i=0; i<sentence.size(); i++){
            if(isspace(sentence[i])) ret++;
        }

        return (ret+1);
    }

    int mostWordsFound(vector<string>& sentences) {
        int ret = 0;
        for(string& s : sentences){
            ret = max(ret, check(s));
        }
        return ret;
    }
};