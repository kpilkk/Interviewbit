// https://www.interviewbit.com/problems/add-binary-strings/

string Solution::addBinary(string A, string B) {
    int m = A.size(), n = B.size();
    int i = m - 1, j = n - 1, carry = 0;
    
    string ans(max(m, n) + 1, '0');
    int si = max(m, n);
    
    while(i >= 0 || j >= 0 || carry){
        int x = i >= 0 ? A[i--] - '0' : 0;
        int y = j >= 0 ? B[j--] - '0' : 0;
        int sum = x + y + carry;
        
        ans[si--] = sum % 2 + '0';
        carry = sum / 2;
    }
    
    if(carry)
        ans[si] = carry + '0';
        
    if(ans[0] == '0')
        return ans.substr(1);
        
    return ans;
}
