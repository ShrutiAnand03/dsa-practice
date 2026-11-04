class Solution {
public:
    int trap(vector<int>& height) {
        // time complexity - o(n)

        int n = height.size();

        if(n<3) return 0;
        int left =0, right = n-1;
        int leftmax =0, rightmax =0;
        int totalwater =0;

        while(left<right){
            if(height[left]<height[right]){
                // update leftmax 
                leftmax = max(leftmax, height[left]);

                //calculate water stored
                totalwater+= leftmax-height[left];
                left++;
            }
            else{
                //calculate rightmax
                rightmax = max(rightmax, height[right]);

                //calculate water stored
                totalwater+= rightmax-height[right];
                right--;
            }
        }

        return totalwater;
    }
};