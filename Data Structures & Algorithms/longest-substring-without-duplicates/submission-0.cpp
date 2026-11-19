class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);   // -1 表示還沒出現過
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            left = max(left, last[s[right]] + 1);
            best = max(best, right - left + 1);
            last[s[right]] = right;
        }
        return best;
    }
};
