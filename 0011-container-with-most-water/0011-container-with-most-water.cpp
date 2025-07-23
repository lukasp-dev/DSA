class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int _max = 0;
        
        while(l<r){
            int left = height[l], right = height[r];
            _max = max(_max, min(left, right)*(r-l));
            if(left<right){
                l++;
            }else if(left>right){
                r--;
            }else{
                l++;
                r--;
            }
        }

        return _max;
    }
};