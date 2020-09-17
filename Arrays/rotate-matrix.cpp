// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    reverse(A.begin(), A.end());
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            swap(A[i][j], A[j][i]);
}

// Interviewbit solution
void Solution::rotate(vector<vector<int> > &A) {
    int len = matrix.size();
    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[len - j - 1][i];
        matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
        matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
        matrix[j][len - i - 1] = tmp;
        }
    }
}
