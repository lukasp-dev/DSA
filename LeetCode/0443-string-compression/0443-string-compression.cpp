class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int streaks = 1;
        for(int i=0; i<chars.size()-1; i++){
            if(chars[i+1] == chars[i]){
                streaks++;
            }else{
                s.push_back(chars[i]);
                if(streaks > 1){
                    string count = to_string(streaks);
                    for(char c : count){
                        s.push_back(c);
                    }
                }

                streaks=1;
            }
        }

        s.push_back(chars[chars.size()-1]);
        if(streaks > 1){
            string count = to_string(streaks);
            for(char c : count){
                s.push_back(c);
            }
        }
        
        chars.clear();
        
        for(int i=0; i<s.length(); i++){
            chars.push_back(s[i]);
        }

        return chars.size();
    }
};