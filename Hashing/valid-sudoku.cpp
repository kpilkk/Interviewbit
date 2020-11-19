// https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &A) {
    bool row[9][9] = {false}, column[9][9] = {false}, box[9][9] = {false};
    
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j)
            if(A[i][j] != '.'){
                int num = A[i][j] - '1', k = i / 3 * 3 + j / 3;
                if(row[i][num] || column[j][num] || box[k][num])
                    return 0;
                row[i][num] = column[j][num] = box[k][num] = 1;
            }
    return 1;
}

// Interviewbit solution
class Solution {
public:
    bool isValidSudoku(vector<string> &board) {
        bool r[9][9], c[9][9], s[3][3][9];
        memset(r, false, sizeof(r));
        memset(c, false, sizeof(c));
        memset(s, false, sizeof(s));
        int number;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] > '0' && board[i][j] <='9') {
                    number = board[i][j] - '1';
                    if (r[i][number]) return false;
                    r[i][number] = true;
                    if (c[j][number]) return false;
                    c[j][number] = true;
                    if (s[i / 3][j / 3][number]) return false;
                    s[i / 3][j / 3][number] = true;
                }
            }
        }
        return true;
    }
};
