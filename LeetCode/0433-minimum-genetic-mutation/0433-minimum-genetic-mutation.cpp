class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bool isInBank = false;

        for(string str : bank){
            if(str == endGene) isInBank = true;
        }

        if(!isInBank) return -1;

        int n = startGene.size();
        int count = 0;
        int cnt = 0;
        unordered_set<string> lookup(bank.begin(), bank.end());
        unordered_set<string> visited;
        vector<char> choices = {'A', 'C', 'G', 'T'};

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        visited.insert(startGene);
        
        while(!q.empty()){
            auto [gene, steps] = q.front(); q.pop();
            if(gene == endGene) return steps;

            for(int i=0; i<n; i++){
                char origin = gene[i];
                for(char c : choices){
                    gene[i] = c;
                    if(!visited.count(gene) && lookup.count(gene)){
                        visited.insert(gene);
                        q.push({gene, steps+1});
                    }
                }
                gene[i] = origin;
            }
        }

        return -1;
    }
};