class Solution {
public:
    bool isHappy(int n) {
        vector<int> check(1000, 0);
        bool flag = true;
        int global_num = n;

        while(flag){
            string number = to_string(global_num);
            int sum = 0;
            for(int i=0; i<number.size(); i++){
                int operand = number[i] - '0';
                sum += operand*operand;
            }
            cout << sum << "\n";
            cout << "visited?: " << check[sum] << "\n";
            if(check[sum] == 1) flag = false;
            check[sum] = 1;
            global_num = sum;
            if(sum == 1) return true;
        }
        return false;
    }
};