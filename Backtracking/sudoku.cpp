// https://www.interviewbit.com/problems/sudoku/

// recursion
bool isSafe(vector<vector<char>>& A, int row, int col, char c){
    for(int i = 0; i < 9; ++i)
        if(A[row][i] == c)
            return false;
    
    for(int i = 0; i < 9; ++i)
        if(A[i][col] == c)
            return false;
    
    for(int i = 3 * (row / 3); i < 3 * (row / 3 + 1); ++i)
        for(int j = 3 * (col / 3); j < 3 * (col / 3 + 1); ++j)
            if(A[i][j] == c)
                return false;
                
    return true;
}

bool solve(vector<vector<char>>& A){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(A[i][j] == '.'){
                for(char c = '1'; c <= '9'; ++c){
                    if(isSafe(A, i, j, c)){
                        A[i][j] = c;
                        if(solve(A))
                            return true;
                        A[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    solve(A);
}
