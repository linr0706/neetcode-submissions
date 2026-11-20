class Solution {
public:
    int characterReplacement(string s, int k) {
        int best = 0;
        for (char c = 'A'; c <= 'Z'; c++) { // 目標：把視窗內所有字元都變成 c
            int left = 0;
            int others = 0; // 視窗內「不是 c」的字元數量 = 要換幾個

            for (int right = 0; right < (int)s.size(); right++) {
                // 1. 加入 s[right]
                if (s[right] != c) others++;

                // 2. 要換的太多了，縮小視窗
                while (others > k) {
                    if (others > k && s[left] != c) others--;
                    left++;
                }

                // 3. 現在視窗合法，記錄長度
                best = max(best, right - left + 1);
            }
        }
        return best;
    }
};
