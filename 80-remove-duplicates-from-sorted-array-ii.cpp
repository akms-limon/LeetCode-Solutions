class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        for (i = 0, j = 0; i < nums.size(); i++) {
            int temp = nums[i], cnt = 0;
            while (i < nums.size() && nums[i] == temp) {
                i++;
                cnt++;
            }
            i--;
            nums[j] = temp;
            j++;
            if (cnt > 1) {
                nums[j] = temp;
                j++;
            }
        }
        return j;
    }
};