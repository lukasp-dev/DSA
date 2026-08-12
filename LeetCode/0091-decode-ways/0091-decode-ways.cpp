class Solution {
private:
    int dfs(string& s, int i, vector<int>& memo) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        if(memo[i] != -1) return memo[i];
        
        int ways = dfs(s, i+1, memo);
        if(i + 1 < s.size()) {
            int num = (s[i]-'0')*10 + (s[i+1]- '0');

            if(num >= 10 && num <= 26) {
                ways += dfs(s, i + 2, memo);
            }
        }

        return memo[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo(n, -1);

        return dfs(s, 0, memo);
    }
};