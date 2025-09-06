class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        auto myReverse = [&](int l, int r){
            for(int i=0; i<(r-l)/2; i++){
                swap(nums[l+i], nums[r-i-1]);
            }
        };

        myReverse(0, n);
        myReverse(0, k);
        myReverse(k, n);
    }
};