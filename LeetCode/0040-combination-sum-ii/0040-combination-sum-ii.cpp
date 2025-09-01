class Solution {
public:
    void makeCombi(vector<vector<int>>& ret, vector<int>& vec, vector<int>& candidates, int start, int target){
        if(target == 0){
            ret.push_back(vec);
        }

        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]) continue; 
            if(candidates[i] > target) break;
            vec.push_back(candidates[i]);
            makeCombi(ret, vec, candidates, i+1, target-candidates[i]);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> vec;
        
        sort(candidates.begin(), candidates.end());

        makeCombi(ret, vec, candidates, 0, target);

        return ret;
    }
};