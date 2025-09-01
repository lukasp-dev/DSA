class Solution {
public:
    void makeCombi(vector<int>& candidates, vector<vector<int>>& ret, vector<int>& vec, int target, int start){
        if(target == 0){
            ret.push_back(vec);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            if(candidates[i] > target) break; // 프루닝
            vec.push_back(candidates[i]);
            makeCombi(candidates, ret, vec, target-candidates[i], i); // 같은게 들어갈 수 있으므로 i 를 넣어준다
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 프루닝 하려면 정렬
        vector<vector<int>> ret;
        vector<int> vec;
        makeCombi(candidates, ret, vec, target, 0);
        return ret;
    }
};