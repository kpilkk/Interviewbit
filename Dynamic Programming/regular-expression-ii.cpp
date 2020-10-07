// https://www.interviewbit.com/problems/regular-expression-ii/

// Recursive solution
int Solution::isMatch(const string A, const string B) {
    if(B.empty()) return A.empty();
    
    int match = !A.empty() && (A[0] == B[0]) || (B[0] == '.');
    
    if(B.size() >= 2 && B[1] == '*')
        return isMatch(A, B.substr(2)) || (match && isMatch(A.substr(1), B));
    else
        return match && isMatch(A.substr(1), B.substr(1));
}

// DP solution
int Solution::isMatch(const string A, const string B) {
    int m = A.size(), n = B.size();
    vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
    dp[0][0] = true;
    
    for(int i = 0; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(B[j - 1] == '*')
                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (A[i - 1] == B[j - 2] || B[j - 2] == '.'));
            else
                dp[i][j] = i && (A[i - 1] == B[j - 1] || B[j - 1] == '.') && dp[i - 1][j - 1];
        }
    }
    return dp[m][n];
}
