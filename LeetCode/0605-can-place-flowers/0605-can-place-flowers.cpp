class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int end = flowerbed.size()-1;

        if(end == 0 && flowerbed[0] == 0 && n == 1){
            return true;
        }

        for(int i=0; i<=end; i++){
            if(flowerbed[i] != 1){
                if(i == 0){
                    if(end>0 && flowerbed[i+1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                    }else if(i == end){
                        if(end>0 && flowerbed[i-1] == 0){
                            flowerbed[i] = 1;
                            n--;
                        }
                    }else{
                        if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                            flowerbed[i] = 1;
                            n--;
                        }
                    }
                }  
            }

        return n <= 0;
    }
};