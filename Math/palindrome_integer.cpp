// https://www.interviewbit.com/problems/palindrome-integer/

// Working code
int reverse(int A){
    int rev = 0;
    while(A){
        if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && A % 10 > 7)) // when reverse(A) overflows
            return -1;
        rev = rev*10 + (A%10);
        A /= 10;
    }
    return rev;
}
int Solution::isPalindrome(int A) {
    if(A<0) return 0;
    if(A>=0 && A<=9) return 1;

    return A == reverse(A);
}

// Solution using string

int Solution::isPalindrome(int A) {
    string s = to_string(A);
    string ss = s;
    reverse(s.begin(), s.end());
    if(s == ss)
        return 1;
    return 0;
}
