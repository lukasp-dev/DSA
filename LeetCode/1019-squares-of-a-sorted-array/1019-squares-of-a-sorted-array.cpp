class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squared(n);

        transform(
            nums.begin(),
            nums.end(),
            squared.begin(),
            [](int x) {
                return x*x;
            }
        );

        sort(squared.begin(), squared.end());
        return squared;
    }
};