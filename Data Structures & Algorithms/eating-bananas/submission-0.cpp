class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxnum = 0;
        int res = 0;
        for(size_t i = 0; i < piles.size(); i++){
            maxnum = max(maxnum, piles[i]);
        }
        int left = 1;
        int right = maxnum;
        while(left <= right){
            long long time = 0;
            int mid = left + (right - left)/2;
            for(size_t j = 0; j < piles.size(); j++){  
                time += ceil((double) piles[j] / mid);
            }
            if(time > h){
                left = mid + 1;
            }
            else{
                right = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};
