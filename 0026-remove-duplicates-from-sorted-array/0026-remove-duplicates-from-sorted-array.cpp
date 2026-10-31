class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;

        while(i<nums.size() && j<nums.size()){
            while(j<nums.size() && nums[i] == nums[j]){
                j++;
            }
            if(j<nums.size()) nums[++i] = nums[j++]; 
        }

        return i+1;
    }
};