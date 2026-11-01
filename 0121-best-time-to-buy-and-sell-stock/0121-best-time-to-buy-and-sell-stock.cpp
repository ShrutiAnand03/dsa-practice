class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int min_val = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            min_val = min(min_val, prices[i]);
            if((i+1) < prices.size()) ans = max(ans, prices[i+1] - min_val);
        }
        return ans;
    }
};