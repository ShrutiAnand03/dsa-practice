class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};


// nums1 = [4,5,6,0,0,0], nums2=[1,2,3] good test case for 2nd while loop, n=3, m=3
// nums1 = [1,2,3,0,0,0], nums2 = [2,5,6] good test case for 1st while loop n=3, m=3


