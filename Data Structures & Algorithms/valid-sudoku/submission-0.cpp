class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {       
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen;
            for (int c = 0; c < 9; c++) {
                char value = board[r][c];

                if(value == '.'){ //跳過空格;單一字元要用''
                    continue;
                }
                else if (seen.count(value) == 1) { // 發現重複數字
                    return false;
                }//檢查是否重複

                else{ //將數字加入 seen
                    seen.insert(value);
                };
            };
        }; 
        for (int c = 0; c < 9; c++) {
            unordered_set<char> seen;
            for (int r = 0; r < 9; r++) {
                char value = board[r][c];

                if(value == '.'){ //跳過空格;單一字元要用''
                    continue;
                }
                else if (seen.count(value) == 1) { // 發現重複數字
                    return false;
                }//檢查是否重複

                else{ //將數字加入 seen
                    seen.insert(value);
                };
            };
        }; 
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> seen;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int row = boxRow + i;
                        int col = boxCol + j;
                        char value = board[row][col]; // 檢查 Box 內的格子
                        if(value == '.'){ //跳過空格;單一字元要用''
                            continue;
                        }
                        else if (seen.count(value) == 1) { // 發現重複數字
                            return false;
                        }//檢查是否重複

                        else{ //將數字加入 seen
                            seen.insert(value);
                        };
                    };
                };
            };
        };
        return true;      
    };
};
