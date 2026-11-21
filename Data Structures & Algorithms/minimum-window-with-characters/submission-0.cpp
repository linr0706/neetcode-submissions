class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        vector<int> need(128, 0), window(128, 0); //整個ASCII(大寫+小寫)
        for (char c : t) need[c]++;
        
        //一開始先數一次，有幾個字母的次數已經相同
        int required = 0;
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) required++;
        }

        int matches = 0;                          // 幾種字元的數量「已經足夠」
        int left = 0;
        int bestLen = INT_MAX, bestStart = 0;     //記錄最短的答案;任何真實長度都比INT_MAX小
        for (int right = 0; right < (int)s.size(); right++) {
            //加入右邊
            int in = s[right];
            window[in]++;
            if (need[in] > 0 && window[in] == need[in]) matches++;  // 剛好足夠
            //合法時才縮，而且一直縮到不合法
            while (matches == required) {
                if (right - left + 1 < bestLen) {    // 記錄更短的答案
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                // 移出左邊
                int out = s[left];
                window[out]--;
                if (need[out] > 0 && window[out] == need[out] - 1) matches--;  //剛好變不夠
                left++;
            };
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
