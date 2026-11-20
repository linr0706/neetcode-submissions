class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> need(26, 0), window(26, 0);
        for (char c : s1) need[c - 'a']++;
        for (int i = 0; i < (int)s1.size() - 1; i++) window[s2[i] - 'a']++;

        // 新增：一開始先數一次，有幾個字母的次數已經相同
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (window[i] == need[i]) matches++;
        }

        int left = 0;
        for (int right = s1.size() - 1; right < (int)s2.size(); right++) {
            // 加入右邊
            int in = s2[right] - 'a';
            window[in]++;
            if (window[in] == need[in]) matches++;           // 剛好對上了
            else if (window[in] == need[in] + 1) matches--;  // 原本對上，現在多一個

            if (matches == 26) return true;                  // 取代 window == need

            // 移出左邊
            int out = s2[left] - 'a';
            window[out]--;
            if (window[out] == need[out]) matches++;          // 剛好對上了
            else if (window[out] == need[out] - 1) matches--; // 原本對上，現在少一個
            left++;
        }
        return false;
    }
};
