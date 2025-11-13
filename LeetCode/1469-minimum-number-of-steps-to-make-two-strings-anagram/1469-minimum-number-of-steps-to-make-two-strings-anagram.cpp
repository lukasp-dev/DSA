class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s_arr(26, 0);
        vector<int> t_arr(26, 0);
        int count = 0;

        for(char c : s){
            s_arr[c - 'a']++;
        }

        for(char c : t){
            t_arr[c - 'a']++;
        }

        for(int i=0; i<26; i++){
            count += abs(t_arr[i]-s_arr[i]);
        }

        return count >> 1;
    }
};