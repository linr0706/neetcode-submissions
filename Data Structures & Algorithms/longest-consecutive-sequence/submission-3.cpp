class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for(int num : numSet){
            if(numSet.count(num-1) == 0){ //判斷num使否適合當起點
                int currentnum = num;
                int currentlength = 1;

                while(numSet.count(currentnum+1) == 1){
                    currentnum++;
                    currentlength++;
                };

                longest = max(longest, currentlength); //更新longest
            }
        };
        return longest;        
    };
};
