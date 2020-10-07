// https://www.interviewbit.com/problems/regular-expression-ii/

// Recursive solution
int Solution::isMatch(const string A, const string B) {
    if(B.empty()) return A.empty();
    
    int match = (A[0] == B[0]) || (B[0] == '.');
    
    if(B.size() >= 2 && B[1] == '*')
        return isMatch(A, B.substr(2)) || (match && isMatch(A.substr(1), B));
    else
        return match && isMatch(A.substr(1), B.substr(1));
}

// DP solution
