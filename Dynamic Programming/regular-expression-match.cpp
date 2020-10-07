// https://www.interviewbit.com/problems/regular-expression-match/

// Recursive solution : TLE
int Solution::isMatch(const string A, const string B) {
    if(B.empty()) return A.empty();
    if(A.empty())
        return B[0] == '*' && isMatch(A, B.substr(1));
    else if(B[0] == '*')
        return isMatch(A, B.substr(1)) || isMatch(A.substr(1), B);
    else
        return (B[0] == '?' || A[0] == B[0]) && isMatch(A.substr(1), B.substr(1));
}
