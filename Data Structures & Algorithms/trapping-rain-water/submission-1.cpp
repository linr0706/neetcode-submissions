class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int area = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                area += leftMax - height[left];
            } 
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                area += rightMax - height[right];
            }
        }
        return area;
    }
};
