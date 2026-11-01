class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        for(int i=0; i<prices.size(); i++){
            if(i+1<prices.size()){
                int val = prices[i+1] - prices[i];
                if(val>0) profit+=val;
            }
        }
        return profit;
    }
};