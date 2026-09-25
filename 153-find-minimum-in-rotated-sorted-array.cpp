class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo =0, hi = n-1, mid; 
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi]){
                lo = mid + 1;
            }
            else hi = mid;
        }
        return nums[lo];
    }
};