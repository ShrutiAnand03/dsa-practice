class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;

        for(int i=0; i<nums.size();i++){
            int needed_num = target - nums[i];
            auto it = mp.find(needed_num);

            if(it!=mp.end()){
                ans.push_back(mp[needed_num]);
                ans.push_back(i);
                break;
            }

            mp[nums[i]] =i;
        }

        return ans;
    }
};