// https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    if(A>=0 && A<=9) return A;
    
    long rev = 0;
    bool neg = false;
    if(A<0){
        neg = true;
        A = -A;
    }
    while(A){
        rev = rev*10 + (A%10);
        A /= 10;
    }
    
    if(neg) rev = -rev;
    if(rev>=INT_MIN && rev<+INT_MAX) return rev;
    return 0;
}
