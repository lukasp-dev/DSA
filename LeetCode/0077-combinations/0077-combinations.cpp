class Solution {
public:
    void combi(vector<vector<int>>& res, vector<int>& vec, int n, int k, int start){
        if(vec.size() == k){
            res.push_back(vec);
            return;
        }

        for(int i = start; i<=n; i++){
            vec.push_back(i);
            combi(res, vec, n, k, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;

        combi(res, vec, n, k, 1);

        return res;
    }
};