class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return 0.0;
        double sum = 0; 
        for(int i=0; i<k; i++)sum+=nums[i];
        if(n == k)return sum/k;

        int l=0;
        double _max = sum;

        for(int r=k; r<n; r++){
            sum-=nums[l]; sum+=nums[r];
            _max = max(_max, sum);
            l++;
        }

        return _max/k;
    }
};