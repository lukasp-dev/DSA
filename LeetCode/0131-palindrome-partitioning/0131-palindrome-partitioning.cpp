class Solution {
public:
    vector<vector<string>> res;

    bool isPalindrome(int l, int r, string& s){
        while(l <= r){
            if(s[l] == s[r]){
                l++; r--;
            }else{
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<string>& path, int start, string& s){
        if(start == s.size()){
            res.push_back(path);
            return;
        }

        for(int end = start; end < s.size(); end++){
            if(isPalindrome(start, end, s)){
                path.push_back(s.substr(start, end - start + 1));
                backtrack(path, end + 1, s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(path, 0, s);
        return res;
    }
};