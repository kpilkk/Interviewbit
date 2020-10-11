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
