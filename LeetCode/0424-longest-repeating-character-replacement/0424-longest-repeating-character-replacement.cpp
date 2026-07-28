class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ret = 1;
        int maxFreq = 1;
        int low = 0;
        int high = 0;
        vector<int> freq(26, 0); 
        
        while(low <= high && high < n){
            freq[s[high] - 'A']++;
            maxFreq = max(maxFreq, freq[s[high] - 'A']);

            if(k < high - low + 1 - maxFreq) {
                freq[s[low] - 'A']--;
                low++;
            }
            
            ret = max(ret, high - low + 1);
            high++;
        }
        
        return ret;
    }
};