class Solution {
public:
    int maxAmount(int n, vector<int>& nums, vector<int>& dp){
        //base condition
        dp[0] = 0;
        dp[1] = nums[0];

        // recursive 
        for(int i=2; i<=n; i++){
            int pick = nums[i-1] + dp[i-2]; 
            int notpick = 0 + dp[i-1]; 

            dp[i] = max(pick,notpick);
        }

        return dp[n];

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
       return maxAmount(n, nums, dp);
    }
};

