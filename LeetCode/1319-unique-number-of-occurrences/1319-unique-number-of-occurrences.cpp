class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2002, 0);

        for(int el : arr) {
            freq[el+1000]++;
        }

        unordered_set<int> lookup;

        for(int el : freq) {
            if(el == 0) continue;

            if(lookup.count(el)) return false;

            lookup.insert(el);
        }

        return true;
    }
};