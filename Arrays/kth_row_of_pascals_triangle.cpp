// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

// O(k) space solution

vector<int> Solution::getRow(int A) {
    int n = A+1;
    vector<int> ans(n);
    ans[0] = 1;
    for(int i=1;i<n;++i)
        for(int j=i;j>=1;--j)
            ans[j] = ans[j] + ans[j-1];
        
    return ans;
}
