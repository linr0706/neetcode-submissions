class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int length = 0;
        unordered_map<char, int> lastPos;
        for (int right = 0; right < s.size(); right++) {   
            if (lastPos.count(s[right]) && lastPos[s[right]] >= left) {
                left = lastPos[s[right]] + 1;
            }
            length = max(length, right - left + 1);
            lastPos[s[right]] = right;
        }
        return length;
    }
};
