// https://www.interviewbit.com/problems/longest-common-prefix/

// Horizontal Scanning
string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    if(n == 0) return "";
    string ans = A[0];
    for(int i = 1; i < n; ++i){
        while(A[i].find(ans) != 0)
            ans = ans.substr(0, ans.length() - 1);
        if(ans.empty())
            return "";
    }
    return ans;
}

// Vertical Scanning
string Solution::longestCommonPrefix(vector<string> &A) {
    if(A.size() == 0) return "";
    for(int i = 0; i < A[0].length(); ++i){
        char c = A[0][i];
        for(int j = 1; j < A.size(); ++j)
            if(i == A[j].length() || A[j][i] != c)
                return A[0].substr(0, i);
    }
    return A[0];
}
