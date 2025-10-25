class Solution {
public:
    pair<int, int> expand(string& s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--; r++;
        }
        return {l+1, r-1};
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";
        int end = 0, start = 0;

        for(int i=0; i<n; i++){
            auto [oddStart, oddEnd] = expand(s, i, i);
            auto [evenStart, evenEnd] = expand(s, i, i+1);

            if(oddEnd - oddStart > end - start){
                end = oddEnd; start = oddStart;
            }
            if(evenEnd - evenStart > end - start){
                end = evenEnd; start = evenStart;
            }
        }

        return s.substr(start, end - start + 1);
    }
};