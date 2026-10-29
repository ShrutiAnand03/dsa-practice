class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <1) return 0;

        sort(nums.begin(), nums.end());
        // for(auto &v: nums){
        //     cout<<v<<"\n";
        // }
        int count = 1;    
        int ans =1;    
        for(int i=1; i<nums.size(); i++){
            // cout<<"nums[i]: "<<nums[i]<<endl;
            // cout<<"(nums[i-1]+1): "<<nums[i-1]+1<<endl;

            if(nums[i] == (nums[i-1]+1)){
                // cout<<"count: "<<count<<"\n";
                count++;
                ans= max(ans, count);
            }
            else if(nums[i] > (nums[i-1]+1)){
                ans = max(ans, count);
                count =1;
            }
            // cout<<"count: "<<count<<endl;
            // cout<<"ans: "<<ans<<endl;

        }

        return ans;
    }
};