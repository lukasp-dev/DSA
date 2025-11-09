class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        vector<int> res(n+m, 0);

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int curr = (num1[i]-'0')*(num2[j]-'0')+res[i+j+1];
                res[i+j+1] = curr%10;
                res[i+j] += curr/10;
            }
        }

        string strRes;
        bool isLeadingZero = true;
        for(int num : res){
            if(num > 0) isLeadingZero = false;
            if(!isLeadingZero) strRes += num+'0';
        }

        return strRes;
    }
};