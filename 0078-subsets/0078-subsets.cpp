class Solution {
public:
    void getSubsets(
        int idx, 
        int n, 
        vector<int>& curr,
        vector<int>& nums, 
        vector<vector<int>>& ans
    ){
        if(idx == n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        getSubsets(idx+1, n, curr, nums, ans);

        curr.pop_back();
        getSubsets(idx+1, n, curr, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int> curr;

        getSubsets(0, n, curr, nums, ans);

        return ans;

    }
};