class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, _max=0;
        int left=0, right=0;
        unordered_map<char, int> um;

        while(right < s.size()){
            _max = max(_max, ++um[s[right]]);
            if ((right - left + 1) - _max > k){
                um[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};