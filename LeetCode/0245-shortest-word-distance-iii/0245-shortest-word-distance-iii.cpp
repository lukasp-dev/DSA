class Solution {
private:
    int getShortestDist(vector<int>& wi1, vector<int>& wi2) {
        int i=0, j=0;
        int min_dist = 1e9;

        while(i < wi1.size() && j < wi2.size()) {
            min_dist = min(min_dist, abs(wi2[j] - wi1[i]));

            if(wi1[i] < wi2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return min_dist;
    }
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> lookup;

        for(int i=0; i<wordsDict.size(); i++) {
            lookup[wordsDict[i]].push_back(i);
        }

        vector<int> wi1 = lookup[word1];
        vector<int> wi2 = lookup[word2];

        if(word1 == word2) {
            int min_dist = 1e9;

            for(int i=1; i<wi1.size(); i++) {
                min_dist = min(min_dist, wi1[i]-wi1[i-1]);
            }

            return min_dist;
        }

        return getShortestDist(wi1, wi2);
    }
};