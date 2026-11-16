class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; // 用來收集答案
        for(size_t i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]){ //連號則繼續
                continue;
            }
            int component = -nums[i];
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(component < sum){
                     right--;
                }
                else if(component > sum){
                    left++;
                }
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--; //避免中間也有相同的結果
                    while(left < right && nums[left] == nums[left - 1]){ //去除重複的
                        left++;
                    }
                };
            };
        };
        return res;    
    };
};
