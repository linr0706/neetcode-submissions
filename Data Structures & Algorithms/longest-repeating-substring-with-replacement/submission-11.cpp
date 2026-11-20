class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxFreq = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);   // 只在加入時更新
            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;    // 移出時「不」更新 maxFreq
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
