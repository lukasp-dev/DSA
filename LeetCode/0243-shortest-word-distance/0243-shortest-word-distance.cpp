class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> indexTable;
        
        for(int i=0; i<wordsDict.size(); i++){
            indexTable[wordsDict[i]].push_back(i);
        }

        int minDist = INT_MAX;

        int l=0, r=0;

        vector<int>& wordIndices1 = indexTable[word1];
        vector<int>& wordIndices2 = indexTable[word2];
        
        while(l < wordIndices1.size() && r < wordIndices2.size()){
            int leftIndex = wordIndices1[l];
            int rightIndex = wordIndices2[r];
            minDist = min(minDist, abs(rightIndex - leftIndex));
            if(leftIndex < rightIndex) l++;
            else r++;
        }

        return minDist;
    }
};