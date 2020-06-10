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
    vector<int> dp(A);
    dp[0] = 1;
    for(int i = 0; i < B; i++) {
        for (int j = 1; j < A; j++) {
            dp[j] += dp[j-1];
        }
    }
    return dp[A-1];
}
