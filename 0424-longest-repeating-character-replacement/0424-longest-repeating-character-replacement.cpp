class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> um;

        int l=0, r=0, _max = 0, range = 0;

        while(r < s.size()){
            _max = max(_max, ++um[s[r]]);
            if(r - l + 1 > _max + k){
                um[s[l]]--;
                l++;
            }
            range = max(range, r-l+1);
            r++;
        }

        return range;
    }
};