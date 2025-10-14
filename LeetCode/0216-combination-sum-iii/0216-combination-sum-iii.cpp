class Solution {
public:
    bool validate(vector<int>& vec, int n){
        int sum = 0;

        for(int i=0; i<vec.size(); i++){
            sum += vec[i];
        }

        return sum == n;
    }

    void combi(int k, vector<int>& vec, vector<vector<int>>& res, int start, int n){
        if(vec.size() == k){
            if(validate(vec, n)) res.push_back(vec);
            return;
        }

        for(int i=start; i<=9; i++){
            vec.push_back(i);
            combi(k, vec, res, i+1, n); 
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> vec;

        combi(k, vec, res, 1, n);

        return res;
    }
};