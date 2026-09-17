class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> frequency_map;
        int count = 0;
        
        for(int el : arr) {
            frequency_map[el]++;
        }

        for(int el : arr){
            if(frequency_map.count(el) && frequency_map.count(el+1)) {
                count += frequency_map.count(el);
            }
        }

        return count;
    }
};