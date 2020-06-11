// https://www.interviewbit.com/problems/largest-coprime-divisor/

// Acceptable Solution -- removing all common factors from B one by one
int Solution::cpFact(int A, int B) {
    int n = __gcd(A,B);
    
    while(n!=1){
        A /= n;
        n = __gcd(A,B);
    }
    return A;
}

// Time Limit Exceeded
int Solution::cpFact(int A, int B) {
    for(int i=A;i>0;--i){
        if(A%i==0){
            if(__gcd(i,B)==1){
                return i;
            }
        }
    }
    return 1;
}
