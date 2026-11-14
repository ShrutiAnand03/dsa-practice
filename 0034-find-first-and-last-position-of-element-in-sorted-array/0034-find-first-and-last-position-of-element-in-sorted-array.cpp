class Solution {
public:
    int findFirstOccurence(int low, int high, vector<int>& nums, int target){
        int firstoccurence = -1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if (nums[mid] == target){
                firstoccurence = mid;
                high = mid -1;
            }
            else if(nums[mid]< target){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }

        return firstoccurence;
    }

    int findLastOccurence(int low, int high, vector<int>& nums, int target){
        int lastoccurence = -1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target){
                lastoccurence = mid;
                low = mid + 1;
            }
            else if(nums[mid]< target){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }

        return lastoccurence;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2, -1);
        int n = nums.size();
        int low =0;
        int high = n-1;

        ans[0] = findFirstOccurence(low, high, nums, target);
        ans[1] = findLastOccurence(low, high, nums, target);

        return ans;
    }
};