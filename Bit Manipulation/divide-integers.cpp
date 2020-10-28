// https://www.interviewbit.com/problems/divide-integers/

int Solution::divide(int A, int B) {
    if(A == B)
        return 1;
        
    if(A == INT_MIN){
        if(B == -1)
            return INT_MAX;
        else if(B == 1)
            return A;
        else{
            return (A & 1) ? divide(A + 1, B) : divide(A >> 1, B >> 1);
        }
    }
    
    if(B == INT_MIN)
        return 0;
    
    bool sign = (A > 0) ^ (B > 0) ? 1 : 0;
    
    A = abs(A);
    B = abs(B);
    
    int ans = 0;
    
    while(A >= B){
        unsigned int temp = B;
        int m = 1;
        while(temp << 1 <= A){
            temp <<= 1;
            m <<= 1;
        }
        A -= temp;
        ans += m;
    }
    
    return sign ? -ans : ans;
}
