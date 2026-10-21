class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return n;

        int i=0, j=1;

        while(i<n && j <n){
            while(j < n && nums[i] == nums[j]){
                j++;
            }
            if (j<n) {
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
};