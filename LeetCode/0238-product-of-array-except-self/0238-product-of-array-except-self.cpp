class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix;
        vector<int> suffix(n);
        
        prefix.push_back(nums[0]); 
        for(int i=1; i<n; i++){
            prefix.push_back(prefix[i-1]*nums[i]);
        }

        suffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = nums[i]*suffix[i+1];
        }

        vector<int> answer(n, 0);
        answer[0] = suffix[1];
        answer[n-1] = prefix[n-2];
        for(int i=1; i<n-1; i++){
            answer[i] = prefix[i-1]*suffix[i+1]; 
        }

        return answer;
    }  
};