// https://www.interviewbit.com/problems/regular-expression-match/

// Recursive solution : TLE
int Solution::isMatch(const string A, const string B) {
    if(B.empty()) return A.empty();
    if(A.empty())
        return B[0] == '*' && isMatch(A, B.substr(1));
    else if(B[0] == '*')
        return isMatch(A, B.substr(1)) || isMatch(A.substr(1), B);
    else
        return (B[0] == '?' || A[0] == B[0]) && isMatch(A.substr(1), B.substr(1));
}

// DP solution
int Solution::isMatch(const string A, const string B) {
    int m = A.size(), n = B.size();
    vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
    dp[0][0] = true;
    
    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            if(i == 0 && j == 0)
                dp[i][j] = true;
            else if(j == 0)
                dp[i][j] = false;
            else if(i == 0)
                dp[i][j] = B[j - 1] == '*' && dp[i][j - 1];
            else if(B[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - 1] && (A[i - 1] == B[j - 1] || B[j - 1] == '?');
        }
    }
    return dp[m][n];
}
