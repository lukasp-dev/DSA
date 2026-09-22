class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        double max_sum=INT_MIN;
        double avg=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            avg=sum/k;
        }
        max_sum=max(max_sum,avg);
        for(int i=k;i<n;i++){
            sum+=nums[i]-nums[i-k];
            avg=sum/k;
            max_sum=max(max_sum,avg);
        }
        return max_sum;
    }
};