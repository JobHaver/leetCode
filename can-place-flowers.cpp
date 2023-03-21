class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size(), end = size-1;

        for(int i=0; i < size && n; i++){
            if(!flowerbed[i] && !flowerbed[max(0, i-1)] && !flowerbed[min(i+1, end)])
                flowerbed[i++]++, n--;
        }

        return !n;
    }
};