class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        for (i = 0, j = 0; i < nums.size(); i++) {
            int temp = nums[i];
            while (i < nums.size() && nums[i] == temp) {
                i++;
            }
            i--;
            nums[j] = temp;
            j++;
        }
        return j;
    }
};