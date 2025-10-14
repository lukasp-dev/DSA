class Solution {
public:
    void makePermutations(vector<vector<int>>& res, vector<int>& vec, vector<int>& nums, vector<int>& visited, int k, int n){
        if(vec.size() == k){
            res.push_back(vec); 
            return;
        }

        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = 1;
            vec.push_back(nums[i]);
            makePermutations(res, vec, nums, visited, k, n);
            vec.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; vector<int> vec;
        int k = nums.size(); int n = nums.size();
        vector<int> visited(n, 0);

        makePermutations(res, vec, nums, visited, k, n);
        
        return res;
    }
};