class Solution {
private:
    double dfs(unordered_map<string, vector<pair<string, double>>>& divisions, unordered_set<string>& visited, string node, string dest){
        visited.insert(node);
        if(node == dest) return 1.0;

        for(pair<string, double>& nei : divisions[node]) {
            if(!visited.count(nei.first)) {
                double result = dfs(divisions, visited, nei.first, dest);
                if(result != -1){
                    return nei.second * result;
                }
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> divisions;

        for(int i=0; i<equations.size(); i++) {
            string key = equations[i][0];
            string divisor = equations[i][1];

            double value = values[i];

            divisions[key].push_back({divisor, value});
            divisions[divisor].push_back({key, 1.0/value});
        }

        vector<double> results(queries.size(),-1.0);
        unordered_set<string> visited;

        // now loop through the queries
        for(int i=0; i<queries.size(); ++i) {
            string a = queries[i][0];
            string b = queries[i][1];

            if(!divisions.count(a) || !divisions.count(b)) {
                continue; 
            }

            results[i] = dfs(divisions, visited, a, b);
            visited.clear();
        }

        return results;
    }
};