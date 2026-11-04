class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1= 0, p2= 0;

        while(p1<m && p2<n){
            if(nums1[p1] <= nums2[p2]){
                p1++;
            }
            else{
                for(int i=m;i>p1;i--){
                    nums1[i] = nums1[i-1];
                }
                nums1[p1] = nums2[p2];
                p2++;
                p1++;
                m++;
            }
        }

        while(p2<n){
            nums1[p1] = nums2[p2];
            p1++;
            p2++; 
        }
    }
};