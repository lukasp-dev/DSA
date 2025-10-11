class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> result;
        int streaks = 1;
        for(int i=0; i<chars.size()-1; i++){
            if(chars[i+1] == chars[i]){
                streaks++;
            }else{
                result.push_back(chars[i]);
                if(streaks > 1){
                    string count = to_string(streaks);
                    for(char c : count){
                        result.push_back(c);
                    }
                }

                streaks=1;
            }
        }

        result.push_back(chars[chars.size()-1]);
        if(streaks > 1){
            string count = to_string(streaks);
            for(char c : count){
                result.push_back(c);
            }
        }
        
        chars = result;

        return chars.size();
    }
};