#include <bits/stdc++.h>
using namespace std;

class MaxStack {
public:
    list<int> stk; // 실제 스택
    map<int, vector<list<int>::iterator>> lookup; // 값 -> 노드 위치들

    MaxStack() {}

    void push(int x) {
        stk.push_back(x);
        lookup[x].push_back(--stk.end());
    }
    
    int pop() {
        int val = stk.back();
        stk.pop_back();
        auto &vec = lookup[val];
        vec.pop_back();
        if (vec.empty()) lookup.erase(val);
        return val;
    }
    
    int top() {
        return stk.back();
    }
    
    int peekMax() {
        return lookup.rbegin()->first;
    }
    
    int popMax() {
        int maxVal = peekMax();
        auto &vec = lookup[maxVal];
        auto it = vec.back(); // list iterator
        stk.erase(it);
        vec.pop_back();
        if (vec.empty()) lookup.erase(maxVal);
        return maxVal;
    }
};
