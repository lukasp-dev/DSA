class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(), candies.end());
        vector<bool> ret;

        for(int candy : candies){
            int addition = candy + extraCandies;
            if(addition >= greatest){
                ret.push_back(true);
            }else{
                ret.push_back(false);
            }
        }

        return ret;
    }
};