class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        for(string token : strs){
            ret += ("" + to_string(token.size()) + "#");
            ret += token;
        }
        cout << "endcoded: " << ret << "\n";
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> tokens;
        int i=0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#') j++;
            int range = stoi(s.substr(i, j-i));
            tokens.push_back(s.substr(j+1,range));
            i = j + 1 + range;
        }
        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));