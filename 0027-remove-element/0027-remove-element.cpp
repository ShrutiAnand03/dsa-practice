class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0,temp;

        while(i < nums.size() && j<nums.size()){
            if(nums[i] == val){
                j = i+1;

                while(j<nums.size() && nums[j] == val){
                    j++;
                }
                if(j<nums.size()){
                    temp = nums[i];
                    nums[i++] = nums[j];
                    nums[j++] = temp;
                }
            }
            else{
                i++;
            }
        }

        return i;
    }
};


