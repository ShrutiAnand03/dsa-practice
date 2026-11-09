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

//                          f(0)
//                        /      \
//                   PICK         SKIP
//                    /             \
//                  f(2)            f(1)
//                 /   \            /   \
//              PICK   SKIP      PICK   SKIP
//               /       \        /       \
//             f(4)      f(3)   f(3)*     f(2)*
//            /  \      /  \ 
//          f(6) f(5)  f(5) f(4)*

// * = Returned from memoization (already calculated).


// Step 1: Start from the bottom
// f(4)

// Value = 1

// max(1 + 0, 0 + 0) = 1
// Returns 1

// f(6) = 0, f(5) = 0


// Step 2: Calculate f(3)
// f(3)

// Pick: 3 + f(5) = 3 + 0 = 3

// Skip: 0 + f(4) = 0 + 1 = 1
// max(3, 1) = 3
// Returns 3



// Step 3: Calculate f(2)
// f(2)

// Pick: 9 + f(4) = 9 + 1 = 10

// Skip: 0 + f(3) = 0 + 3 = 3
// max(10, 3) = 10
// Returns 10



// Step 4: Calculate f(1)
// f(1)

// Pick: 7 + f(3) = 7 + 3 = 10

// Skip: 0 + f(2) = 0 + 10 = 10
// max(10, 10) = 10
// Returns 10


// Step 5: Calculate f(0)
// f(0)

// Pick: 2 + f(2) = 2 + 10 = 12

// Skip: 0 + f(1) = 0 + 10 = 10
// max(12, 10) = 12