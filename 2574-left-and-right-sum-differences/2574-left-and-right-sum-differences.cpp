class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int>leftsum(n);
        vector<int>rightsum(n);
        vector<int>ans(n);


        for(int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }

        for(int i=0; i<n; i++){
            if(i ==0) leftsum[i] =0;
            else{
                leftsum[i] = nums[i-1];
            }
        }

        for(int i=0; i<n; i++){
            rightsum[i] = nums[n-1] - nums[i];
        }

        // for(int i=0; i<n; i++){
        //     cout<<leftsum[i]<<" ";
        // }
        // cout<<"\n";


        // for(int i=0; i<n; i++){
        //     cout<<rightsum[i]<<" ";
        // }
        // cout<<"\n";

        for(int i=0; i<n; i++){
            ans[i] = abs(leftsum[i]-rightsum[i]);
        }

        // for(int i=0; i<n; i++){
        //     cout<<ans[i]<<" ";
        // }

        return ans;

    }
};