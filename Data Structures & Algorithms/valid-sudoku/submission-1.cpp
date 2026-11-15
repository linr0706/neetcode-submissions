class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.'){
                    continue;
                }
                
                int num = board[r][c] - '1'; // 數字轉換成索引(1~9 -> 0~8)
                int box = (r / 3) * 3 + (c / 3); // 對應的九宮格編號

                if (rows[r][num] ||cols[c][num] ||boxes[box][num]) {
                    return false;
                }

                rows[r][num] = true; //同一列已經出現過這個數字
                cols[c][num] = true;
                boxes[box][num] = true;
            };
        };
        return true;
    }
};
