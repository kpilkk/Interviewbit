// https://www.interviewbit.com/problems/maximum-absolute-difference/

// Working solution - O(n)
int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int i=0;i<n;++i){
        max1 = max(max1, A[i]+i);
        min1 = min(min1, A[i]+i);
        max2 = max(max2, A[i]-i);
        min2 = min(min2, A[i]-i);
    }
    return max(max1-min1, max2-min2);
}

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
