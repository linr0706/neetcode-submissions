class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(target == nums[mid]) return mid;
            else if(nums[mid] >= nums[left]){ //左半是排好的
                if( target >= nums[left] && target < nums[mid]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            else{ //右半是排好的
                if( target <= nums[right] && target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
