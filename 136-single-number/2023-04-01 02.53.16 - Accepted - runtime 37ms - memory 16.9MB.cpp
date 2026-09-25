class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=INT_MIN;
        for(int i = 0; i<nums.size()-1; i++){
            int cnt = 1;
            while(nums[i]==nums[i+1] && i<nums.size()){
                cnt++;
                i++;
            }
            if(cnt==1) {
                ans = nums[i];
                break;
            }
        }
        if(ans==INT_MIN) return nums[nums.size()-1];
        return ans;
    }
};