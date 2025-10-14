class Solution {
public:

    void backtrack(string& digits, int idx, string& curr, vector<string>& res, unordered_map<char, string>& lookup){
        if(curr.size() == digits.size()){
            res.push_back(curr);
            return;
        }

        for(char c : lookup[digits[idx]]){
            curr.push_back(c);
            backtrack(digits, idx+1, curr, res, lookup);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> lookup;

        lookup['2'] = "abc";
        lookup['3'] = "def";
        lookup['4'] = "ghi";
        lookup['5'] = "jkl";
        lookup['6'] = "mno";
        lookup['7'] = "pqrs";
        lookup['8'] = "tuv";
        lookup['9'] = "wxyz";

        vector<string> res;
        string curr;

        int n = digits.length();

        backtrack(digits, 0, curr, res, lookup);

        return res;
    }
};