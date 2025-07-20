class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size());
        int prefix = 1, postfix = 1;
        v[0] = prefix;

        for(int i=1; i<nums.size(); i++){
            prefix *= nums[i-1];
            v[i] = prefix;
        }

        for(int i=nums.size()-2; i>=0; i--){
            postfix *= nums[i+1];
            v[i] = v[i]*postfix;
        }
        

        return v;
    }
};