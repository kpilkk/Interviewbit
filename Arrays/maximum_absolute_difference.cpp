// https://www.interviewbit.com/problems/maximum-absolute-difference/

// Time Limit Exceeded - brute force solution
int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    for(int i=0;i<n-1;++i){
        for(int j=i;j<n;++j){
            ans = max((abs(A[i]-A[j])+abs(i-j)), ans);
        }
    }
    return ans;
}
