class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %=n;

        vector<int>temp;

        for(int i=0; i<n; i++){
            if(i<k){
                temp.push_back(nums[n-k+i]);
            }
            else {
                temp.push_back(nums[i-k]);
            }
        }
       
        for(int i=0; i<n; i++){
            nums[i] = temp[i];
        }
    }
};