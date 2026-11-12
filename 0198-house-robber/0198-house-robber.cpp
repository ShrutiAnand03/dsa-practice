class Solution {
public:
    int maxAmount(int n, vector<int>& nums){
        //base condition
        if(n == 0) return 0;

        int prev2=0;
        int prev1=nums[0];

        // recursive 
        for(int i=2; i<=n; i++){
            int pick = nums[i-1] + prev2; 
            int notpick = 0 + prev1; 

            int curr = max(pick,notpick);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return maxAmount(n, nums);
    }
};

