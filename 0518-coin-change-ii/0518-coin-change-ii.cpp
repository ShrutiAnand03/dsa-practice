class Solution {
public:
    int noOfcombinations(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(idx == 0) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        // recursive case
        if(coins[idx-1]<=amount){
            //pick
            int pick = noOfcombinations(idx, amount - coins[idx-1], coins, dp);
            
            //not pick
            int notpick = noOfcombinations(idx-1, amount, coins, dp);

            return dp[idx][amount] = pick + notpick;
        }

        return dp[idx][amount] = noOfcombinations(idx-1, amount, coins, dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return noOfcombinations(n, amount, coins, dp);
    }
};

// [1,2,5]
// 1->pick , notpick
// 2->pick , notpick