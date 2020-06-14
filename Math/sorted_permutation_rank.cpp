// https://www.interviewbit.com/problems/sorted-permutation-rank/

long long factorial(long long n){
    if(n==0 || n==1) return 1;
    return (n*factorial(n-1))%1000003;
}

int Solution::findRank(string A) {
    int mod = 1000003;
    int n = A.size();

    long long rank = 0;
    
    for(int i=0;i<n;++i){
        int temp = 0;
        for(int j=i+1;j<n;++j){
            if(A[j]<A[i]) ++temp;
        }
        rank = (rank+temp*factorial(n-1-i))%mod;
    }
    rank = (rank+1)%mod;
    return rank;
}
