class Solution {
public:
    void getCombinations(
        int idx,
        int target,
        vector<int>& candidates,
        vector<int>& combination,
        vector<vector<int>>& ans
    ){
        // base case
        if(idx == candidates.size()){
            if(target == 0) {
                ans.push_back(combination);
            }

            return;
        }

        // recursive case
        if(candidates[idx]<= target){
            combination.push_back(candidates[idx]);
            getCombinations(idx, target-candidates[idx], candidates, combination, ans);
            combination.pop_back();
        }
        getCombinations(idx+1, target, candidates, combination, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combination;

        getCombinations(
            0, 
            target, 
            candidates,
            combination,
            ans
        );

        return ans;
    }
};