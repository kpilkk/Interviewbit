// https://www.interviewbit.com/problems/multiply-strings/

string Solution::multiply(string A, string B) {
    int m = A.size(), n = B.size();
    string ans(m + n, '0');
    
    for(int i = m - 1; i >= 0; --i){
        for(int j = n - 1; j >= 0; --j){
            int sum = (A[i] - '0') * (B[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = (sum % 10) + '0';
            ans[i + j] += (sum / 10);
        }
    }
    
    for(int i = 0; i < m + n; ++i){
        if(ans[i] != '0')
            return ans.substr(i);
    }
    return "0";
}
