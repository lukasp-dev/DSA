class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int iSum = 0;

        for(int i=0; i<k; i++){
            iSum += nums[i];
        }

        int greatest = iSum;

        if(nums.size() == k){
            return (double)iSum/k;
        }

        int l=0, r=k-1;

        while(r < nums.size()){
            iSum -= nums[l];
            l++;r++;
            iSum += nums[r];

            greatest = max(greatest, iSum);
        }
        
        return (double)greatest/k;        
    }
};