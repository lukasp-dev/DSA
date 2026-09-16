class Solution {
private:
    vector<int> merge(vector<int>& A, vector<int>& B) {
        vector<int> result;
        int i = 0, j = 0;

        while(i<A.size() && j<B.size()) {
            if(A[i] <= B[j]){
                result.push_back(A[i]);
                ++i;
            } else {
                result.push_back(B[j]);
                ++j;
            }
        }    

        while(i < A.size()) {
            result.push_back(A[i]);
            ++i;
        }

        while(j < B.size()) {
            result.push_back(B[j]);
            ++j;
        }

        return result;
    }



public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        
        int mid = nums.size() / 2;

        vector<int> L(nums.begin(), nums.begin() + mid);
        vector<int> R(nums.begin() + mid, nums.end());

        vector<int> sortedL = sortArray(L);
        vector<int> sortedR = sortArray(R);

        return merge(sortedL, sortedR);
    }
};