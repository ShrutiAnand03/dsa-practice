class Solution {
public:
    int minCoins(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(idx == 0) return 1e9;
        if(dp[idx][amount]!= -1) return dp[idx][amount];

        if(coins[idx-1] <= amount){
            // pick
            int pick = 1 + minCoins(idx, coins, amount-coins[idx-1], dp);

            //notpick
            int notpick = 0 + minCoins(idx-1, coins, amount, dp);

            return dp[idx][amount]= min(pick, notpick);
        }

        return dp[idx][amount]= minCoins(idx-1, coins, amount, dp);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans= minCoins(n, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};