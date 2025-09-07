class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightAcc(n, 0);
        int mult = 1;

        for(int i=n-1; i>=0; i--){
            mult *= nums[i];
            rightAcc[i] = mult;
        }

        vector<int> leftAcc(n, 0);
        mult = 1;

        for(int i=0; i<n; i++){
            mult *= nums[i];
            leftAcc[i] = mult;
        }

        vector<int> ret(n, 0);
        ret[0] = rightAcc[1];
        ret[n-1] = leftAcc[n-2];
        for(int i=1; i<n-1; i++){
            ret[i] = leftAcc[i-1]*rightAcc[i+1];
        }
        return ret;
    }
};