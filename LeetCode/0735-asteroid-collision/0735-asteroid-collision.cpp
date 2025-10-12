class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int curr : asteroids) {
            if (!stk.empty() && curr < 0) {
                bool destroyed = false;

                // 1) 더 작은 양수는 전부 제거
                while (!stk.empty() && stk.top() > 0 && stk.top() < -curr) {
                    stk.pop();
                }

                // 2) 같은 크기면 서로 소멸 -> curr도 소멸, 여기서 끝!
                if (!stk.empty() && stk.top() > 0 && stk.top() == -curr) {
                    stk.pop();
                    destroyed = true;      // curr 소멸
                }
                // 3) 남은 top이 더 크면 curr 소멸 (아무 것도 안 함)
                else if (!stk.empty() && stk.top() > 0 && stk.top() > -curr) {
                    destroyed = true;      // curr 소멸
                }

                if (!destroyed) {
                    // 스택이 비었거나 음수만 남아 있으면 curr를 넣는다
                    stk.push(curr);
                }
            } else {
                stk.push(curr);
            }
        }

        vector<int> ret(stk.size());
        for (int i = (int)stk.size() - 1; i >= 0; --i) {
            ret[i] = stk.top(); stk.pop();
        }
        return ret;
    }
};
