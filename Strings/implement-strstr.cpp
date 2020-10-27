// https://www.interviewbit.com/problems/implement-strstr/

// Brute force
int Solution::strStr(const string A, const string B) {
    int m = A.length(), n = B.length();
    if(m == 0 || n == 0)
        return -1;
        
    for(int i = 0; i < m; ++i){
        if(A[i] == B[0]){
            int j = i, k = 0;
            while(k < n && j < m){
                if(A[j] != B[k])
                    break;
                else{
                    ++k, ++j;
                }
            }
            if(k == n)
                return i;
        }
    }
    return -1;
}

// KMP algorithm
vector<int> kmp(string needle){
    int n = needle.length();
    vector<int> lps(n , 0);
    
    for(int i = 1, len = 0; i < n;){
        if(needle[i] == needle[len])
            lps[i++] = ++len;
        else if(len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

int Solution::strStr(const string A, const string B) {
    int m = A.length(), n = B.length();
    
    if(!n)
        return -1;

    vector<int> lps = kmp(B);
    for(int i = 0, j = 0; i < m;){
        if(A[i] == B[j])
            ++i, ++j;
        if(j == n)
            return i - j;
        if(i < m && A[i] != B[j])
            j ? j = lps[j - 1] : i++;
    }
    return -1;
}
