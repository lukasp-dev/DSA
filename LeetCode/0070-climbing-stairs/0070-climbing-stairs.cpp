class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int> numOfWaysAtIndexArray(n+1, 0);
    
        numOfWaysAtIndexArray[0] = 1;
        numOfWaysAtIndexArray[1] = 1;

        for(int i=2; i<n+1; i++){
            numOfWaysAtIndexArray[i] = numOfWaysAtIndexArray[i-1] + numOfWaysAtIndexArray[i-2];
        }
        
        return numOfWaysAtIndexArray[n];
    }
};