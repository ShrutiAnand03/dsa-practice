class Solution {
public:
    int maxAmount(int n, vector<int>& nums, vector<int>& dp){
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        if(dp[n]!=-1) return dp[n];

        int pick = nums[n-1] + maxAmount(n-2, nums, dp);
        int notpick = 0 + maxAmount(n-1, nums, dp);

        return dp[n] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int>nums1;
        vector<int>nums2;

        for(int i=0; i<nums.size(); i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=nums.size()-1) nums2.push_back(nums[i]);
        }

        vector<int>dp1(nums1.size()+1, -1);
        vector<int>dp2(nums2.size()+1, -1);
        
        return max(
            maxAmount(nums1.size(), nums1, dp1),
            maxAmount(nums2.size(), nums2, dp2)
        );
    }
};