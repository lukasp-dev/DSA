class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();

        if(s_size < p_size) {
            return {};
        }

        vector<int> window(26, 0);
        vector<int> target(26, 0); 

        for(int i=0; i<p_size; i++) {
            window[s[i] - 'a']++;
            target[p[i] - 'a']++;
        }

        vector<int> ret;
        if (window == target) ret.push_back(0);

        for(int right = p_size; right < s_size; right++) {
            window[s[right - p_size] - 'a']--;
            window[s[right] - 'a']++;
            
            if(window == target) {
                ret.push_back(right - p_size + 1);
            }
        }

        return ret;
    }
};