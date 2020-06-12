// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

// Solution using Extra Memory -- Acceptable on Interviewbit
vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    // if(n==0) 
    vector<int> B(A);
    sort(B.begin(), B.end());
    
    int left = 0, right = 0;
    for(int i=0;i<n;++i){
        if(B[i]!=A[i]){
            left = i;
            break;
        }
    }
    
    for(int i=left;i<n;++i){
        if(B[i]!=A[i]){
            right = i;
        }
    }
    if(left==0 && right==0) return {-1};
    return {left, right};
}
