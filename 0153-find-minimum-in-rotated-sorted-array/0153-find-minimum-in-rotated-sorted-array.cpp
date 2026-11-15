class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start =0;
        int end = n-1;

        while(start<=end){
            int mid = start + (end - start)/2;

            // if the array is already sorted
            if(nums[start]<=nums[end]){
                return nums[start];
            }

            if(mid>0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }

            if(nums[start]<=nums[mid]){
                start = mid+1;
            }
            else{
                end = mid -1;
            }
        }

        return 0;
    }
};