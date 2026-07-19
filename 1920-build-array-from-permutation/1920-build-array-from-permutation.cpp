class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            ans[i] = nums[nums[i]];
        }

        return(ans);
    }
};


// 0 1 2 3 4 5
//[0,2,1,5,3,4]

// arr[0] = nums[nums[0]]  = nums[0] =0 
// arr[1] = nums[nums[1]] = nums[2] = 1
// arr[2] =nums[nums[2]] = nums[1] =2
