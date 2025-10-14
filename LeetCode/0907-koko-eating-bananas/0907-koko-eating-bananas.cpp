class Solution {
public:
    bool canEatUp(vector<int>& piles, int k, int h){
        long long time = 0;
        for(int pile : piles){
            time += (pile%k) ? pile/k+1 : pile/k;
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(canEatUp(piles, mid, h)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};