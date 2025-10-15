class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            int cur = nums[i];

            if(cur < 0) swap(maxProd, minProd);
            
            maxProd = max(cur, maxProd * cur);
            minProd = min(cur, minProd * cur);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};
