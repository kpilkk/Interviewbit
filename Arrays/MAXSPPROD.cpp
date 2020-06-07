// https://www.interviewbit.com/problems/maxspprod/?ref=similar_problems

// My solution : time limit exceeded

int leftspecialvalue(vector<int> &A, int i){
    if(i==0) return 0;
    int val = 0;
    for(int j=i-1;j>=0;--j){
        if(A[j]>A[i]){
            val = j;
            break;
        }
    }
    return val;
}

int rightspecialvalue(vector<int> &A, int i){
    if(i==A.size()) return 0;
    int val = 0;
    for(int j=i+1;j<A.size();++j){
        if(A[j]>A[i]){
            val = j;
            break;
        }
    }
    return val;   
}

int Solution::maxSpecialProduct(vector<int> &A) {
    int mod = 1000000007;
    int ans = 0;
    
    for(int i=0;i<A.size();++i){
        // cout << ans << " ";
        ans = max(leftspecialvalue(A,i)*rightspecialvalue(A,i), ans);
    }
    
    return ans%mod;
}
