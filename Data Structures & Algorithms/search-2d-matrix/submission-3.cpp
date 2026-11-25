class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        int row = -1;
        while(left <= right){
            int mid = left + (right -left)/2;
            if(matrix[mid][matrix[0].size()-1] < target){
                left = mid + 1;
            }
            else if(matrix[mid][0] > target){
                right = mid - 1;
            }
            else{
                left = 0;
                right = matrix[0].size()-1;
                while (left <= right) { 
                    int midd = left + (right - left) / 2;                            
                    // 範圍裡還有東西
                    if (matrix[mid][midd] < target) {
                        left = midd + 1;                        // 太小，答案在右邊
                    }
                    else if (matrix[mid][midd] > target) {
                        right = midd - 1;                       // 太大，答案在左邊
                    }
                    else {
                        return true;
                    }
                }   
            }
        };
        return false;                                // 找不到
    }
};
