class Solution {
public:
    long long solve( 
        int idx, 
        int n, 
        vector<int>& nums,
        int player,
        vector<vector<long long>>& dp
    ){
      //solve(idx, player) returns the optimal score difference (Alice's score − Bob's score) from index idx to the end of the array, assuming both players play optimally.

        // base condition
        if(idx == n)return 0;

        if(dp[idx][player]!=-1) return dp[idx][player];

        // initialising the players
        // who will be the next player comes from a condition so i need two variables to maintain the next player from the current player.
        int nextplayer1 = player;
        int nextplayer2 = player;

        long long sum1 = nums[idx]*1LL;
        if(sum1%3 == 0) nextplayer1 = 1-player;

        long long contribution1 = (player == 0) ? sum1 : -sum1;
        long long score1 = contribution1 + solve(idx+1, n, nums, nextplayer1, dp);

        // pick two elememts only if the choice is available
        long long score2 =0;

        if(idx+1<n){
            long long sum2 = nums[idx] + nums[idx + 1];

            if (sum2 % 3 == 0)
                nextplayer2 = 1 - player;

            long long contribution2 = (player == 0) ? sum2 : -sum2;

            score2 = contribution2 + solve(idx+2, n, nums, nextplayer2, dp);
        }
        if(player == 0){
            return dp[idx][player] = max(score1, score2);
        } 
        
        return dp[idx][player] = min(score1, score2);
        
    }

    long long maxDifference(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>>dp(n, vector<long long>(2, -1));

        return solve(0, n, nums, 0, dp);
    }
};