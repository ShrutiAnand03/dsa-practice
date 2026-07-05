class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto v: nums){
            mp[v]++;
        }

        for(auto v: mp){
            if(v.second > (nums.size() /2)){
                return v.first;
            }
        }

        return -1;
    }
};