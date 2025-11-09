class Solution {
public:
    struct cmp{
        bool operator()(const int& a, const int& b)const{
            return a > b;
        }
    };

    string intToRoman(int num) {
        string res = "";

        map<int, string, cmp> value = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        for(auto& p : value){
            while(num >= p.first){
                num = num - p.first;
                cout << num << "\n";
                res+=p.second;
            }
        }

        return res;
    }
};