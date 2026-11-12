class Solution {
public:
    int maxAmount(int n, vector<int>& nums){        
        int prev2=0;
        int prev1=nums[0];

        for(int i=2; i<=n; i++){
            int pick = nums[i-1] + prev2;
            int notpick = 0 + prev1;
            int curr = max(pick, notpick);

            prev2 =prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int>nums1;
        vector<int>nums2;

        for(int i=0; i<nums.size(); i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=nums.size()-1) nums2.push_back(nums[i]);
        }

        return max(
            maxAmount(nums1.size(), nums1),
            maxAmount(nums2.size(), nums2)
        );
    }
};