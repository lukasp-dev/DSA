class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> stk;
        int i = digits.size() - 1;
        int carry = 1;

        // 뒤에서부터 더하기
        for (; i >= 0; i--) {
            int sum = digits[i] + carry;
            stk.push(sum % 10);
            carry = sum / 10;
            if (carry == 0) { 
                // 남은 부분은 그대로 stack에 넣고 종료
                i--;
                while (i >= 0) {
                    stk.push(digits[i]);
                    i--;
                }
                break;
            }
        }

        // 아직 carry 남으면 stack에 추가
        if (carry) stk.push(carry);

        // stack → digits 로 덮어쓰기
        digits.clear();
        while (!stk.empty()) {
            digits.push_back(stk.top());
            stk.pop();
        }

        return digits;
    }
};
