// https://www.interviewbit.com/problems/rain-water-trapped/

// DP solution
int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int ans = 0;
    vector<int> left_max(n), right_max(n);
    left_max[0] = A[0];
    for(int i = 1; i < n; ++i)
        left_max[i] = max(left_max[i - 1], A[i]);
        
    right_max[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; --i)
        right_max[i] = max(right_max[i + 1], A[i]);
    
    for(int i = 0; i < n; ++i)
        ans += min(left_max[i], right_max[i]) - A[i];
    
    return ans;
}
