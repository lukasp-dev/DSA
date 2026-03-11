class Solution {
public:
    vector<string> ret;
    void backtrack(string& curr, string digits, unordered_map<char, string>& lookup, int index){
        if(curr.size() == digits.size()){
            ret.push_back(curr);
            return;
        }
        
        for(char c : lookup[digits[index]]){
            curr.push_back(c);
            backtrack(curr, digits, lookup, index+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> lookup = {
            {'2', "abc"}, 
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        string curr = "";

        backtrack(curr, digits, lookup, 0);

        return ret;
    }
};