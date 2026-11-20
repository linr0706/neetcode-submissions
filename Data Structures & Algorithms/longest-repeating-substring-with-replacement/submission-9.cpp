class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);  // count[0] = 'A' 的次數，count[1] = 'B'……
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right] - 'A']++;  // 'C' - 'A' = 2，所以 'C' 存在 count[2]
            while ((right - left + 1) - *max_element(count.begin(), count.end()) > k){
                count[s[left] - 'A']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
