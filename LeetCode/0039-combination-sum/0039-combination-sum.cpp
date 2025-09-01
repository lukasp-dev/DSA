class Solution {
public:
    void makeCombi(vector<int>& candidates, vector<vector<int>>& ret, vector<int>& vec, int target, int start){
        if(target <= 0){
            ret.push_back(vec);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            if(candidates[i] > target) return;
            vec.push_back(candidates[i]);
            makeCombi(candidates, ret, vec, target-candidates[i], i);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> vec;
        makeCombi(candidates, ret, vec, target, 0);
        return ret;
    }
};