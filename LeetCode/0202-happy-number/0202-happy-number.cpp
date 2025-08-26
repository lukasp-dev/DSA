class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        bool flag = true;
        int global_num = n;

        while(flag){
            string number = to_string(global_num);
            int sum = 0;
            for(int i=0; i<number.size(); i++){
                int operand = number[i] - '0';
                sum += operand*operand;
            }

            if(set.find(sum) != set.end()) flag = false;
            set.insert(sum);
            global_num = sum;
            if(sum == 1) return true;
        }
        return false;
    }
};