class Solution {
public:
    void getSubsets(
        int idx,
        int n,
        vector<int>& nums,
        vector<int>& curr,
        vector<vector<int>>& ans
    ){
        if(idx==n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        getSubsets(idx+1, n, nums, curr, ans);
        curr.pop_back();

        int nextidx = idx+1;
        while(nextidx<n && nums[nextidx] == nums[idx]) nextidx++;
        getSubsets(nextidx, n, nums, curr, ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;

        sort(nums.begin(), nums.end());
        getSubsets(0, nums.size(), nums, curr, ans);
        return ans;
    }
};