class Solution {
private:
    double dfs(unordered_map<string, vector<pair<string, double>>>& lookup, unordered_set<string>& visited, string dest, string node) {
        if(node == dest) return 1.0;
        visited.insert(node);

        for(auto nei : lookup[node]) {
            auto [to, val] = nei;
            if (visited.count(to)) continue;
            double found = dfs(lookup, visited, dest, to);
            if(found != -1.0) return val*found; 
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        if(n != values.size()) return {};

        unordered_map<string, vector<pair<string, double>>> lookup;
        
        for(int i=0; i<n; i++) {
            const vector<string>& equation = equations[i];
            string from = equation[0];
            string to = equation[1];
            double val = values[i];
            
            lookup[from].push_back({to, val});
            lookup[to].push_back({from, 1/val});
        }

        int m = queries.size();
        vector<double> ret(m, -1.0);
        unordered_set<string> visited;

        for(int i=0; i<m; i++) {
            string from = queries[i][0];
            string to = queries[i][1];

            if(!lookup.count(from) || !lookup.count(to)) {
                continue;
            }

            ret[i] = dfs(lookup, visited, to, from);
            visited.clear();
        }

        return ret;
    }
};