// https://www.interviewbit.com/problems/grid-unique-paths/

// Using combination
int Solution::uniquePaths(int A, int B) {
    int m = A+B-2;
    int n = min(A-1,B-1);
    
    long long ans = 1;
    for(int i=0;i<n;++i){
        ans *= (m-i);
    }
    
    for(int i=0;i<n;++i){
        ans /= (n-i);
    }
    
    return ans;
}

// Using recursion
int Solution::uniquePaths(int A, int B) {
    if(A==0 && B==0) return 0;
    if(A==1 || B==1) return 1;
    else return uniquePaths(A-1, B) + uniquePaths(A, B-1);
}

// Using DP
int Solution::uniquePaths(int A, int B) {
    vector<vector<int>> dp(A, vector<int>(B, 1));
    for (int i = 1; i < A; i++) {
        for (int j = 1; j < B; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[A - 1][B - 1];
}
