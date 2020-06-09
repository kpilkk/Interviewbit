// https://www.interviewbit.com/problems/verify-prime/

int Solution::isPrime(int A) {
    if(A<=1) return 0;
    int x = sqrt(A);
    
    for(int i=2;i<=x;++i){
        // cout << i << " ";
        if(A%i==0) return 0;
    }
    return 1;
}
