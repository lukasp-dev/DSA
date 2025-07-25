class Solution {
public:
    bool check(vector<int>& piles, const int& k, const int& h){
        long long time = 0;
        for(int pile : piles){
            time += pile/k;
            if(pile%k){
                time++;
            }
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        sort(piles.begin(), piles.end());
        int ans;

        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(check(piles, mid, h)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};