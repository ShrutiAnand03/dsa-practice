class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0, right = height.size()-1;
        int width, length;
        int ans =0;

        while(left<right){
            width = right - left;
            length = min(height[left], height[right]);

            ans = max(ans, width*length);

            if(height[left]<=height[right]) left++;
            else right --;
        }

        return ans;
    }
};