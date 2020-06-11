// https://www.interviewbit.com/problems/power-of-two-integers/

// 1st solution
int Solution::isPower(int A) {
    if(A==1) return 1;
    for(int i=2;i<=sqrt(A);++i){
        int n = log(A)/log(i);
        if(pow(i,n) == A) return 1;
    }
    return 0;
}

// 2nd solution

int Solution::isPower(int A) {
    if(A==1) return 1;

    float p;
    for(int i=2;i<=sqrt(A);++i){
        p = log(A)/log(i);
        if((ceil(p)==floor(p)) && p > 1)
            return 1;
    }
    return 0;
}

// 3rd solution
// Memory Limit Exceeded

int Solution::isPower(int A) {
    vector<bool> sieve(A+1, false);
    
    sieve[1] = true;
    
    for(int i=2;i<=A;++i){
        if(!sieve[i]){
            for(int j=i*i;j<=A;j*=i){
                sieve[j] = true;
            }
        }
    }
    return sieve[A];
}
