// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    reverse(A.begin(), A.end());
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            swap(A[i][j], A[j][i]);
}
