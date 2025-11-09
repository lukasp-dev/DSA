class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s_arr(26, 0);
        vector<int> t_arr(26, 0);

        for(char c : s) s_arr[c - 'a']++;
        for(char c : t) t_arr[c - 'a']++;

        int res = 0;
        for(int i=0; i<26; i++){
            res += abs(t_arr[i] - s_arr[i]);
        }

        return res>>1;
    }
};