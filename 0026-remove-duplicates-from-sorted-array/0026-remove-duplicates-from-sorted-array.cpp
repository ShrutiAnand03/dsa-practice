class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int n = nums.size();
        // if(n == 1) return n;

        // int i=0, j=1;

        // while(j <n){
        //     while(j < n && nums[i] == nums[j]){
        //         j++;
        //     }
        //     if (j<n) {
        //         nums[++i] = nums[j];
        //         j++;
        //     }
        // }
        // return i+1;

        int n = nums.size();
        if(n == 1) return n;

        int i=0;

        for(int j=1; j<n; j++){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};