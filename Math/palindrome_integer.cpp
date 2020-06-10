// https://www.interviewbit.com/problems/palindrome-integer/

// Working code
int reverse(int A){
    int rev = 0;
    while(A){
        rev = rev*10 + (A%10);
        A /= 10;
    }
    return rev;
}
int Solution::isPalindrome(int A) {
    if(A<0) return 0;
    if(A>=0 && A<=9) return 1;
    // this program will fail if reversed array overflows
    
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
