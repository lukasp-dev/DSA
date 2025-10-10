class Solution {

vector<string> split(string s, char delimiter){
    vector<string> ret;
    string token;
    istringstream ss(s);
    while(getline(ss, token, delimiter)){
        if(!token.empty())
            ret.push_back(token);
    }

    return ret;
}

string trim(string s){
    int l=0, r=s.size()-1;

    while(s[l] == ' '){
        l++;
    }

    while(s[r] == ' '){
        r--;
    }

    return s.substr(l, r-l+1);
}

public:
    string reverseWords(string s) {
        s = trim(s);

        vector<string> list = split(s, ' ');
        int l = 0, r = list.size() - 1;

        while (l < r) {
            swap(list[l], list[r]);
            l++; r--;
        }

        string ret;
        for (int i = 0; i < list.size(); i++) {
            if (i) ret += " ";
            ret += list[i];
        }
        return ret;
    }
};