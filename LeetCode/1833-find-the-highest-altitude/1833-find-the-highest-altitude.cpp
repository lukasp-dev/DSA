class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_h = 0;
        int prefix = 0;
        
        for(int dh : gain){
            prefix += dh;
            max_h = max(max_h, prefix);
        }

        return max_h;
    }
};