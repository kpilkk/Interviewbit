// https://www.interviewbit.com/problems/largest-coprime-divisor/

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
