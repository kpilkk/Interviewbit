// https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    if(n==0 || n==1) return -1;
    
    // As there is one extra element, so there must be repitition
    int ans = 0;
    
    for(int i=0;i<n;++i){
        ans ^= A[i];
        ans ^= i;
    }
    return ans;
}
