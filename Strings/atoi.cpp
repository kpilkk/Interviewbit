// https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    int n = A.length();
    
    int i = 0;
    while(i < n && A[i] == ' ')
        ++i;
        
    int sign = 1;
    if(i < n && (A[i] == '+' || A[i] == '-'))
        sign = (A[i++] == '-') ? -1 : 1;
    
    int result = 0;
    while(i < n && A[i] >= '0' && A[i] <= '9'){
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && (A[i] - '0') > 7))   // INT_MAX % 10 = 7
            return sign == 1 ? INT_MAX : INT_MIN;
        result = result * 10 + (A[i++] - '0');
    }
    
    return result * sign;
}
