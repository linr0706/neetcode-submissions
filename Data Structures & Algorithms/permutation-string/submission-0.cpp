class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        // 新增：用次數陣列判斷「排列」
        vector<int> need(26, 0), window(26, 0);
        for (char c : s1) need[c - 'a']++;   // s1 每個字母的次數
        for (int i = 0; i < (int)s1.size() - 1; i++) window[s2[i] - 'a']++;  // 先放入 s2 的前 n-1 個字元

        int left = 0;
        for (int right = s1.size() - 1; right < (int)s2.size(); right++) {
            window[s2[right] - 'a']++;          // 加入右邊，視窗剛好 n 格
            if (window == need) return true;    // 次數完全相同 → 找到排列
            window[s2[left] - 'a']--;           // 移出左邊，準備往右滑
            left++;
        }
        return false;
    }
};