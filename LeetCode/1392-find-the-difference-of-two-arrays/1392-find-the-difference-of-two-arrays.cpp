class Solution {
public:

    map<int, int> makeHashMap(vector<int>& nums){
        map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        return mp;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1;
        map<int, int> mp2;

        mp1 = makeHashMap(nums1);
        mp2 = makeHashMap(nums2);

        vector<vector<int>> ret;
        unordered_set<int> set1;
        unordered_set<int> set2;

        for(int num : nums1){
            if(mp2.find(num) == mp2.end()){
                set1.insert(num);
            }
        }

        for(int num : nums2){
            if(mp1.find(num) == mp1.end()){
                set2.insert(num);
            }
        }

        vector<int> vec1(set1.begin(), set1.end());
        vector<int> vec2(set2.begin(), set2.end());

        ret.push_back(vec1);
        ret.push_back(vec2);

        return ret;
    }
};