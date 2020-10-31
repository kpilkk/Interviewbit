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

// Using stack
int Solution::longestValidParentheses(string A) {
    int n = A.size();
    int ans = 0;
    stack<int> temp;
    temp.push(-1);
    
    for(int i = 0; i < n; ++i){
        if(A[i] == '(')
            temp.push(i);
        else{
            temp.pop();
            if(temp.empty())
                temp.push(i);
            else
                ans = max(ans, i - temp.top());
        }
    }
    return ans;
}

// Without using extra space
int Solution::longestValidParentheses(string A) {
    int left = 0, right = 0, ans = 0, n = A.size();
    
    for(int i = 0; i < n; ++i){
        if(A[i] == '(')
            ++left;
        else
            ++right;
        if(left == right)
            ans = max(ans, 2 * right);
        else if(right > left)
            left = right = 0;
    }
    
    left = right = 0;
    
    for(int i = n - 1; i >= 0; --i){
        if(A[i] == '(')
            ++left;
        else
            ++right;
        if(left == right)
            ans = max(ans, 2 * right);
        else if(left > right)
            left = right = 0;
    }
    
    return ans;
}
