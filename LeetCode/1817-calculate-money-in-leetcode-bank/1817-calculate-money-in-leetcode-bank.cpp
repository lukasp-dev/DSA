class Solution {
public:
    int totalMoney(int n) {
        int res = 0;

        if(n < 7){
            for(int i=0; i<n; i++){
                res += (i+1);
            }
        }else{
            int money = 28;
            int i=0;
            for(i=1; i<=n/7; i++){
                res += money;
                money = money+7;
            }

            for(int j=i; j<i+n%7; j++){
                res += j;
            }
        }

        return res;
    }
};