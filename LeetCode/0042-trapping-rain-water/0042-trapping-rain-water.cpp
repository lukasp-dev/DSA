class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> dec_mono_stack;
        int ans = 0;

        for(int i=0; i<n; i++) {
            while(!dec_mono_stack.empty()
                && height[dec_mono_stack.top()] < height[i]) {
                    int bottom_idx = dec_mono_stack.top();
                    dec_mono_stack.pop();
                    if(dec_mono_stack.empty()) break;

                    int left_idx = dec_mono_stack.top();

                    int bounded_height = min(height[i], height[left_idx]) - height[bottom_idx];

                    ans += bounded_height*(i-left_idx-1);
            }

            dec_mono_stack.push(i);
        }

        return ans;
    }
};