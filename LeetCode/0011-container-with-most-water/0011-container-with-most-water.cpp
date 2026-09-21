class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int _max = 0;

        while(l < r) {
            int curr = min(height[l], height[r]) * (r-l);
            _max = max(_max, curr);

            if(height[l] < height[r]) {
                l++;
            } else if(height[l] > height[r]) {
                r--;
            } else {
                l++;r--;
            }
        }

        return _max;
    }
};