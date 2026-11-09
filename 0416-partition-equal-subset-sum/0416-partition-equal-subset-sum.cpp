class Solution {
public:
    bool solve(int n, vector<int>& nums, int sum, vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(n == 0) return false;
        if(dp[n][sum]!=-1) return dp[n][sum];

        if(nums[n-1]<=sum){
            //pick
            bool pick = solve(n-1, nums, sum-nums[n-1], dp);

            // notpick
            bool notpick = solve(n-1, nums, sum, dp);

            return dp[n][sum] = pick || notpick;
        }

        return dp[n][sum] = solve(n-1, nums, sum, dp);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum =0;

        for(auto v: nums){
            totalsum+=v;
        }
        vector<vector<int>>dp(n+1, vector<int>((totalsum/2)+1, -1));

        if(totalsum%2!=0) return false;
        return solve(n, nums, totalsum/2, dp);
    }
};