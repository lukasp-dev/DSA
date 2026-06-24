class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(string s : strs){
            encoded += to_string(s.size());
            encoded += '#';
            encoded += s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        int n = s.size();
        vector<string> ret;

        while(i < n){
            int j = i;

            while(s[j] != '#'){
                ++j;
            }

            int len = stoi(s.substr(i, j - i));
            ++j;
            
            ret.push_back(s.substr(j, len));

            i = j + len;
        }

        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));