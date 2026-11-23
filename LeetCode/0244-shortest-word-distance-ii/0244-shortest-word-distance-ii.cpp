class WordDistance {
public:
    unordered_map<string, vector<int>> index_map;

    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); ++i) {
            string word = wordsDict[i];
            index_map[word].push_back(i);
        }
    }

    int getShortest(vector<int>& wi1, vector<int>& wi2){
        int i = 0, j = 0;
        int min_dist = 1e9;

        while(i < wi1.size() && j < wi2.size()) {
            int index1 = wi1[i];
            int index2 = wi2[j];

            min_dist = min(min_dist, abs(index2 - index1));

            if(index1 < index2) {
                i++;
            }else{
                j++;
            }
        }

        return min_dist;
    }
    
    int shortest(string word1, string word2) {
        vector<int> indices1 = index_map[word1];
        vector<int> indices2 = index_map[word2];

        return getShortest(indices1, indices2);
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */