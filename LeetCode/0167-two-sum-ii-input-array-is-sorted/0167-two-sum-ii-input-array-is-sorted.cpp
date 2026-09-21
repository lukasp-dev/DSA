class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> seen; // val, index
        
        for(int i=1; i<=numbers.size(); i++) {
            int curr = numbers[i-1];
            int complement = target - curr;
            if(seen.count(complement)){
                return {seen[complement], i};
            }

            seen.insert({curr, i});
        }

        return {-1, -1};
    }
};