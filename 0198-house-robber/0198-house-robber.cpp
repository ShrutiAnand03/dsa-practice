class Solution {
public:
    int maxAmount(int n, vector<int>& nums, vector<int>& dp){
        //base condition
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(dp[n]!= -1) return dp[n];

        // recursive 
        int pick = nums[n-1] + maxAmount(n-2, nums, dp);

        int notpick = 0 + maxAmount(n-1, nums, dp);
        return dp[n] =max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
       return maxAmount(n, nums, dp);
    }
};

