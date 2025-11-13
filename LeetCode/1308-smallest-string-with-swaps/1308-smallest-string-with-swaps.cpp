class Solution {
public:
    vector<int> parent;
    vector<int> rank;

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
        else if(rank[pa] < rank[pb]){
            parent[pa] = pb;
        }else if(rank[pa] > rank[pb]){
            parent[pb] = pa;
        }else{
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        rank.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(vector<int>& pair : pairs){
            unite(pair[0], pair[1]);
        }

        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[find(i)].push_back(i);
        }


        string str = s;
        for(auto& kv : mp){
            vector<int>& indices = kv.second;
            sort(indices.begin(), indices.end());

            string temp = "";
            for(int i : indices){
                temp += s[i];
            }
            sort(temp.begin(), temp.end());
            for (int k = 0; k < indices.size(); k++) {
                str[indices[k]] = temp[k];
            }
        }
        return str;
    }
};