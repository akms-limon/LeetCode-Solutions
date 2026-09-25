class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                if (i == 0) {
                    if (flowerbed.size() > 1 && flowerbed[i + 1] == 0) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                    else if (flowerbed.size() == 1) {
                        cnt++;
                    }
                }
                else if (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) {
                    cnt++;
                }
                else if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    cnt++;
                }
            }
        }
        if (cnt >= n) return true;
        return false;
    }
};