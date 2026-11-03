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

// Optimized approach — Two Pointers
// Step 1: Initialize two pointers
// - left = 0
// - right = n-1
// Initially, we consider the container formed by the first and last bars.

// Step 2: Calculate the area

// For every iteration:
// - Width = right - left
// - Height = min(height[left], height[right])
// - Area = Height × Width
// - Update the maximum area.
// Step 3: Decide which pointer to move

// This is the most important insight!
// - The amount of water is controlled by the shorter bar.
// - If the left bar is shorter, move left forward.
// - If the right bar is shorter, move right backward.