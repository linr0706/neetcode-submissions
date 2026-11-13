class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int rightProduct = 1;
        vector<int> output(nums.size(), 1);
        for(size_t i = 1; i < nums.size(); i++){           
            output[i] = output[i-1] * nums[i-1];
        };

        for(int j = static_cast<int>(nums.size())-1; j >= 0; j--){           
            output[j] =rightProduct * output[j];
            rightProduct *= nums[j]; 
        };

        return output;
    };
};
