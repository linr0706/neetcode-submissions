class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string&word : strs){
            auto len = word.size();
            encoded +=to_string(len) +'#'+ word;
        };
        return encoded;
    };

    vector<string> decode(string s) {
        vector<string> result;
        size_t i = 0;
        while(i < s.size()){   
            size_t j = s.find('#', i); //s.find(要尋找的字元, 開始搜尋的位置);
            string lengthText = s.substr(i, j-i); //s.substr(起始位置, 擷取長度)
            int len = stoi(lengthText); //將字串轉成整數
            string word = s.substr(j+1, len); //j的位子在#，word從下一位開始
         
            result.push_back(word); //將 word 加入 result
            i = j + len + 1; //更新 i 到下一個區塊起點
        };
        return result;
    };
};
