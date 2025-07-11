class Solution {
public:
    void print(vector<int>& v){
        for(int it : v){
            cout << it << " ";
        }
        cout << "\n";
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> ret(n,0);

        int mult = 1;

        for(int i=0; i<n; i++){
            left[i] = nums[i]*mult;
            mult = left[i];
        }

        mult = 1;

        for(int i=n-1; i>=0; i--){
            right[i] = nums[i]*mult;
            mult = right[i];
        }

        print(left);
        print(right);

        for(int i=0; i<n; i++){
            if(i == 0){
                ret[i] = right[i+1];
            } else if(i == n-1){
                ret[i] = left[i-1];
            } else{
                ret[i] = left[i-1]*right[i+1];
            }
        }
        
        return ret;
    }
};