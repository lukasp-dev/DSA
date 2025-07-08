class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;

        for(string& str : word1){
            for(char ch : str){
                str1 += ch;
            }
        }

        for(string& str : word2){
            for(char ch : str){
                str2 += ch;
            }
        }

        return str1 == str2;
    }
};