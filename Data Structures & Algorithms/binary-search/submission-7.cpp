class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;                           // 最後一個元素的位置

        while (left <= right) {                              // 範圍裡還有東西
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;                        // 太小，答案在右邊
            }
            else if (nums[mid] > target) {
                right = mid - 1;                       // 太大，答案在左邊
            }
            else {
                return mid;
            }
        }
        return -1;                                // 找不到
    }
};
