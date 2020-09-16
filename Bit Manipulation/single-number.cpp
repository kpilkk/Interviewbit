// https://www.interviewbit.com/problems/single-number/

int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int ans = A[0];
    
    for(int i = 1; i < n; ++i)
        ans ^= A[i];
        
    return ans;
}
