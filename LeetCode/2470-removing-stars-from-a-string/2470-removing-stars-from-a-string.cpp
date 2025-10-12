class Solution {
public:
    string removeStars(string s) {
        string ret = "";

        for(char c : s){
            if(c == '*'){
                if(!ret.empty()){
                    ret.pop_back();
                }
            }else{
                ret += c;
            }
        }

        return ret;
    }
};