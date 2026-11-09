class Solution {
public:
    void getCombinations(
        int idx, 
        int target, 
        vector<int>& candidates,
        vector<int>& combination, 
        vector<vector<int>>& ans
    ){
        if(target == 0){
            ans.push_back(combination);
            return;
        }

        for(int i =idx; i<candidates.size(); i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            
            if(candidates[i] > target) break;
            
            combination.push_back(candidates[i]);
            getCombinations(
                i+1, 
                target - candidates[i], 
                candidates, 
                combination, 
                ans
            );
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>combination;
        vector<vector<int>>ans;

        sort(candidates.begin(), candidates.end());
        getCombinations(0, target, candidates, combination, ans);
        return ans;
    }
};