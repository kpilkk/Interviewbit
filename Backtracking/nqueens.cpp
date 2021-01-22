// https://www.interviewbit.com/problems/nqueens/

bool isValid(vector<string>& nQueens, int row, int col, int n){
    for(int i = 0; i < row; ++i)
        if(nQueens[i][col] == 'Q')
            return false;
    
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if(nQueens[i][j] == 'Q')
            return false;
            
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if(nQueens[i][j] == 'Q')
            return false;
    
    return true;
}

void solve(vector<vector<string>>& ans, vector<string>& nQueens, int row, int n){
    if(row == n){
        ans.push_back(nQueens);
        return;
    }
    
    for(int col = 0; col < n; ++col){
        if(isValid(nQueens, row, col, n)){
            nQueens[row][col] = 'Q';
            solve(ans, nQueens, row + 1, n);
            nQueens[row][col] = '.';  // backtrack
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> ans;
    vector<string> nQueens(A, string(A, '.'));
    solve(ans, nQueens, 0, A);
    return ans;
}
