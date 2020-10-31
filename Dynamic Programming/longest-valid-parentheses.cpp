// https://www.interviewbit.com/problems/longest-valid-parentheses/

// DP solution
int Solution::longestValidParentheses(string A) {
    int n = A.length();
    vector<int> dp(n , 0);
    int ans = 0;
    
    for(int i = 1; i < n; ++i){
        if(A[i] == ')'){
            if(A[i - 1] == '(')
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            else if(i - dp[i - 1] > 0 && A[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
