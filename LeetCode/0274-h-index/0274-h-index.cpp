class Solution {
public:
    bool simulate(vector<int> citations, int number){
        int cnt = 0;

        for(int i=0; i<citations.size(); i++){
            if(citations[i] >= number){
                cnt++;
            }
        }

        return cnt >= number;
    }

    int hIndex(vector<int>& citations) {
        int r = *max_element(citations.begin(), citations.end());
        int l = 0;
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(simulate(citations, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return ans;
    }
};
