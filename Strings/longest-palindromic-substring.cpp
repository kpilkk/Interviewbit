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

// Manacher's Algorithm
string Solution::longestPalindrome(string A) {
    int n = A.length();
    int len = 2 * n + 1;
    string temp(len, '#');
    
    int k = 1;
    for(auto i : A){
        temp[k] = i;
        k += 2;
    }
    
    vector<int> p(len, 0);
    int centre = 0, right = 0;
    int maxCentre = 0, maxLen = 0;
    for(int i = 0; i < len; ++i){
        int iMirror = 2 * centre - i;
        if(right > i)
            p[i] = min(right - i, p[iMirror]);
            
        while(i - p[i] >= 0 && i + p[i] < len && temp[i - p[i] - 1] == temp[i + p[i] + 1])
            ++p[i];
        
        if(p[i] > maxLen){
            maxLen = p[i];
            maxCentre = i;
        }
        
        if(i + p[i] > right){
            centre = i;
            right = i + p[i];
        }
    }
    return A.substr((maxCentre - maxLen) / 2, maxLen);
}
