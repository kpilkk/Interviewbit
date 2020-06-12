// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

// Solution using Kedane's algorithm

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    if(n==0) return 0;
    if(n==1) return A[0];
    
    int local_sum = A[0], global_sum = A[0];
    for(int i=1;i<n;++i){
        local_sum = max(A[i], local_sum+A[i]);
        global_sum = max(global_sum, local_sum);
    }
    return global_sum;
}
