class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> set1; set<char> set2;
        unordered_map<char, int> mp1; unordered_map<char, int> mp2;

        for(char c : word1){
            set1.insert(c);
            mp1[c]++;
        }

        for(char c : word2){
            set2.insert(c);
            mp2[c]++;
        }

        if(set1 != set2) return false;

        priority_queue<int> pq1; priority_queue<int> pq2;
        for(auto it : mp1){
            pq1.push(it.second);
        }

        for(auto it : mp2){
            pq2.push(it.second);
        }

        while(!pq1.empty() && !pq2.empty()){
            if(pq1.top() != pq2.top()){
                return false;
            }

            pq1.pop(); pq2.pop();
        }

        return pq1.empty() && pq2.empty();
    }
};

// 1. we have the same set of alphabets
// 2. we have the same set of occurrence of each number (but doesn't have to be the same alphabet)