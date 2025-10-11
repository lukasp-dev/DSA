class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> minimum(n);
        vector<int> maximum(n);

        int minSoFar = nums[0];
        for(int i=0; i<n; i++){
            minSoFar = min(minSoFar, nums[i]);
            minimum[i] = minSoFar;
        }

        int maxSoFar = nums[n-1];
        for(int i=n-1; i>=0; i--){
            maxSoFar = max(maxSoFar, nums[i]);
            maximum[i] = maxSoFar;
        }

        for(int i=1; i<n-1; i++){
            if(minimum[i-1] < nums[i] && maximum[i+1] > nums[i]){
                return true;
            }
        }

        return false;
    }
};