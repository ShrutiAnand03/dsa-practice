class Solution {
public:
    void getsubsets(
        int idx, 
        int n,
        vector<int>&nums, 
        vector<int>&curr,
        vector<vector<int>>& ans
    ){
        if(idx == n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        getsubsets(idx+1, n, nums, curr, ans);
        curr.pop_back();
        getsubsets(idx+1, n, nums, curr, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>ans;
        vector<int>curr;
        getsubsets(0, n, nums, curr, ans);
        return ans;
    }
};