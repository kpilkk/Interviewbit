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
