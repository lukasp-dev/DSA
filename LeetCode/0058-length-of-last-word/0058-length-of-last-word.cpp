class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;

        int len = 0;
        int ptr = s.size() - 1;

        while(isspace(s[ptr])) ptr--;

        while(ptr>=0 && !isspace(s[ptr])) {
            len++;
            ptr--;    
        }
        return len;
    }
};