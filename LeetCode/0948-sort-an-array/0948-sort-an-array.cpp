class Solution {
vector<int> merge(vector<int>& L, vector<int>& R) {
    int l = 0, r = 0;
    vector<int> result;

    while(l < L.size() && r < R.size()) {
        if(L[l] <= R[r]) {
            result.push_back(L[l]);
            l++;
        } else {
            result.push_back(R[r]);
            r++;
        }
    }

    while(l < L.size()) {
        result.push_back(L[l]);
        l++;
    }

    while(r < R.size()) {
        result.push_back(R[r]);
        r++;
    }

    return result;
}

public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;

        int mid = nums.size()/2;
        vector<int> L(nums.begin(), nums.begin() + mid); 
        vector<int> R(nums.begin() + mid, nums.end());

        vector<int> sortedL = sortArray(L);
        vector<int> sortedR = sortArray(R);

        return merge(sortedL, sortedR);
    }
};