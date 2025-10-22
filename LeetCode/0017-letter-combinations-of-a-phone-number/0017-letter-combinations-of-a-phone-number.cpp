class Solution {
public:
    vector<string> res;

    void backtrack(string& digits, string curr, unordered_map<char, string>& lookup, int idx){
        if(curr.size() == digits.size()){
            res.push_back(curr);
            return;
        }

        for(char c : lookup[digits[idx]]){
            curr.push_back(c);
            backtrack(digits, curr, lookup, idx+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> lookup;
        lookup['2'] = "abc";
        lookup['3'] = "def";
        lookup['4'] = "ghi";
        lookup['5'] = "jkl";
        lookup['6'] = "mno";
        lookup['7'] = "pqrs";
        lookup['8'] = "tuv";
        lookup['9'] = "wxyz";

        string curr;
        
        backtrack(digits, curr, lookup, 0);

        return res;
    }
};