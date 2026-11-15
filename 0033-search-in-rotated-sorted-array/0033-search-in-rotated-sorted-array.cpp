class Solution {
public:
    int findMinElementIndex(int start, int end, vector<int>& nums){
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[start]<=nums[end]){
                return start;
            }

            if(mid>0 && nums[mid]<=nums[mid-1]){
                return mid;
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
    int binarySearch(int start, int end, vector<int>& nums, int target){
        while(start<=end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;

        int minElementIdx = findMinElementIndex(0, n-1, nums);

        int firsthalf = binarySearch(0, minElementIdx-1, nums, target);
        int secondhalf = binarySearch(minElementIdx, n-1, nums, target);

        
        if(firsthalf == -1) return secondhalf;
        else return firsthalf;
    }
};