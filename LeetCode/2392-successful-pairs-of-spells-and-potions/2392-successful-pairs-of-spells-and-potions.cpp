class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ret;

        for(int spell : spells){
            int l=0, r=m-1, first = m;
            while(l <= r){
                int mid = l + (r-l)/2;

                long long cmp = (long long)spell * potions[mid];
                
                if(cmp >= success){
                    first = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }

            ret.push_back(m - first);
        }

        return ret;
    }
};