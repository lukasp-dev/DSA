class Solution {
public:
    void getCombination(int N, int K, int start, vector<vector<int>>& ret, vector<int> vec){
        if(vec.size() == K){
            ret.push_back(vec);
            return;
        }

        for(int i=start; i<=N; i++){
            vec.push_back(i);
            getCombination(N, K, i + 1, ret, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int N, int K) {
        vector<vector<int>> ret;
        vector<int> vec;
        getCombination(N, K, 1, ret, vec);

        return ret;
    }
};