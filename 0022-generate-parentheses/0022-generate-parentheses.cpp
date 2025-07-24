class Solution {
public:
    void go(vector<string>& ret, vector<int>& count, string str, const int& n){
        if(str.size() == 2*n && count[0] == n && count[1] == n){
            ret.push_back(str);
            return;
        }
        int numOpen = count[0];
        int numClose = count[1];

        if(numOpen < numClose) return;
        if(numOpen > n || numClose > n) return;

        count[0]++; 
        str += "(";
        go(ret, count, str, n);
        str.erase(str.size()-1, 1);
        count[0]--;

        count[1]++; 
        str += ")";
        go(ret, count, str, n);
        str.erase(str.size()-1, 1);
        count[1]--;
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        
        string str;
        vector<int> count = {0, 0};

        go(ret, count, str, n);
        return ret;
    }
};