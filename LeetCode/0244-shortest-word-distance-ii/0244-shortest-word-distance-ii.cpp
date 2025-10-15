class WordDistance {
public:
    unordered_map<string, vector<int>> indexMap;

    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); i++){
            string word = wordsDict[i];
            indexMap[word].push_back(i);
        }
    }

    int getShortest(vector<int>& wi1, vector<int>& wi2){
        int i=0, j=0;
        int minDist = INT_MAX;

        while(i < wi1.size() && j < wi2.size()){
            int index1 = wi1[i];
            int index2 = wi2[j];

            minDist = min(minDist, abs(index1 - index2));

            if(index1 < index2) i++;
            else j++;
        }

        return minDist;
    }
    
    int shortest(string word1, string word2) {
        vector<int>& wordIndices1 = indexMap[word1];
        vector<int>& wordIndices2 = indexMap[word2];

        return getShortest(wordIndices1, wordIndices2);
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */