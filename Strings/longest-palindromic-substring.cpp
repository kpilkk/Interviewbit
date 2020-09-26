// https://www.interviewbit.com/problems/longest-palindromic-substring/

// O(n2) complexity by expanding around centre

string expand(string A, int begin, int end, int n){
    while(begin >= 0 && end <= n - 1 && A[begin] == A[end])
        begin--, end++;
        
    return A.substr(begin + 1, end - begin - 1);
}
string Solution::longestPalindrome(string A) {
    int n = A.length();
    if(n <= 1) return A;
    
    string longest = A.substr(0, 1);
    for(int i = 0; i < n; ++i){
        string temp = expand(A, i, i, n);
        if(temp.length() > longest.length())
            longest = temp;
        temp = expand(A, i, i + 1, n);
        if(temp.length() > longest.length())
            longest = temp;
    }
    return longest;
}
