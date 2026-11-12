class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> result;
        for (int i = 0; i < static_cast<int>(strs.size()); i++) {

            array<int, 26> count{};
            for (char c : strs[i]) {
                count[c - 'a']++;// 將目前字元的出現次數加一
            };

            // 建立 Frequency Key
            string key = "";

            for (int j = 0; j < 26; j++) {
            key += to_string(count[j]) + "#";// 加入分隔符號 "#"
            };

            groups[key].push_back(strs[i]);
        };

        for (const auto& entry : groups){
            result.push_back(entry.second);
        }; 

        return result;
    };
};
