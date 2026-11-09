class Solution {
public:
    int maxSum(
        int idx, 
        int n, 
        vector<int>& nums,
        vector<int>& dp
    ){
        if(idx >=n){
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];
        int left = nums[idx] + maxSum(idx+2, n, nums, dp);
        int right = 0 + maxSum(idx+1, n, nums, dp);

        return dp[idx] = max(left, right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);

        return maxSum(0, n, nums, dp);
    }
};