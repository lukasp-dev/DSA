class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;

        auto it = max_element(candies.begin(), candies.end());
        int max_el = *it;

        for(int candy : candies){
            if(candy + extraCandies >= max_el){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }

        return res;
    }
};