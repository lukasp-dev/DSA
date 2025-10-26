class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        if(n==1) return nums;
        vector<int> suffix(n, 0);
        suffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1]*nums[i];
        }

        vector<int> res;
        int prefix = nums[0];
        res.push_back(suffix[1]);

        for(int i=1; i<n-1; i++){
            res.push_back(prefix*suffix[i+1]);
            prefix*=nums[i];
        }

        res.push_back(prefix);

        return res;
    }
};