class Solution {
public:
    int findPivotIndex(int left, int right, vector<int>nums, int n){
        int leftsum =0, rightsum=0;

        if(left !=0) leftsum =nums[left-1];
        if(left != n-1) rightsum = nums[right] - nums[left];

        if(leftsum == rightsum) return left;

        return -1;
    }
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int ans =-1;

        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }
        for(int i =0; i<n; i++){
            ans = findPivotIndex(i, n-1, nums, n);
            if(ans!=-1) return ans;
        }

        return ans;
    }
};
