class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> collisions;

        for(int a : asteroids) {
            if(a < 0) {
                while(!collisions.empty() && collisions.top() > 0 && abs(collisions.top()) < abs(a)) {
                    collisions.pop();
                }

                if(!collisions.empty()) {
                    if(collisions.top() > 0) {
                        if(abs(collisions.top()) > abs(a)) continue;
                        else if(abs(collisions.top() == abs(a))) {
                            collisions.pop(); continue;
                        }
                    }
                }

                collisions.push(a);
            } else {
                collisions.push(a);
            }
        }

        vector<int> answer;
        while(!collisions.empty()) {
            answer.push_back(collisions.top());
            collisions.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};