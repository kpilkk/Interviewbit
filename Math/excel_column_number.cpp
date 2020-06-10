// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    int ans = 0;
    int n = A.size();
    
    for(int i=0;i<n;++i){
        ans += (A[i]-'A'+1)*pow(26,n-1-i);
    }
    return ans;
}
