class Solution {
private:
    bool canEatAll(vector<int>& piles, int eating_rate, int h) {
        int time_took = 0;
        for(int pile : piles) {
            time_took += pile/eating_rate;
            if(pile%eating_rate) time_took++;
        }

        return time_took <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l < r) {
            long long mid = l + (r - l)/2;

            if(canEatAll(piles, mid, h)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};