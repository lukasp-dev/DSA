class Solution {
public:
    string decodeString(string s) {
        stack<int> numbers;
        stack<string> strings;
        int number = 0;
        string code;

        for(int c : s) {
            if(isdigit(static_cast<unsigned char>(c))){
                number = number*10 + (c - '0');
            }
            else if(c == '['){
                numbers.push(number);
                strings.push(code);

                number = 0;
                code = "";
            } else if(c == ']') {
                int n = numbers.top();
                numbers.pop();

                string prev = strings.top();
                strings.pop();
                
                string repeated;
                for(int i=0; i<n; ++i) {
                    repeated += code;
                }

                code = prev + repeated;
            } else {
                code += c;
            }
        }

        return code;
    }
};