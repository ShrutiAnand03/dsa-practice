class Solution {
public:
    int solve(int n, vector<int>& nums, int target, int sum){
        if(n == 0){
            if(target == sum) return 1;
            return 0;
        }

        // add (use +)
        int add = solve(n-1, nums, target, sum+nums[n-1]);

        // subtract (use -)
        int sub = solve(n-1, nums, target, sum-nums[n-1]);


        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum =0;
        return solve(n, nums, target, 0);
    }
};