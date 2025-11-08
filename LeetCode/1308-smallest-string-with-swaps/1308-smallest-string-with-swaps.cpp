class Solution {
private:
    vector<int> parent;
    vector<int> rank;
public:
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;
        else if(rank[pa] > rank[pb]){
            parent[pb] = pa;
        }else if(rank[pa] < rank[pb]){
            parent[pa] = pb;
        }else{
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;

        for(auto p : pairs){
            unite(p[0], p[1]);
        }

        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[find(i)].push_back(i);
        }

        string res = s;

        for(auto &kv : mp){
            vector<int>& indices = kv.second;
            string temp = "";
            for(int i=0; i<indices.size(); i++){
                temp += s[indices[i]];
            }
            sort(temp.begin(), temp.end());
            for(int i=0; i<indices.size(); i++){
                res[indices[i]] = temp[i];
            }
        }

        return res;
    }
};