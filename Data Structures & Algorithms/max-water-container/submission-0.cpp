class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int res = 0;
        while(left < right){
            res = max(res,min(heights[left], heights[right]) * (right-left));
            if(heights[left] <= heights[right]){
                left++;
            }
            else{
                right--;
            } 
        };   
        return res; 
    };
};
