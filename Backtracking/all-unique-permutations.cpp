// https://www.interviewbit.com/problems/all-unique-permutations/

// Iterative solution using next Permutation
bool nextPermutation(vector<int>& A){
    int i = A.size() - 2;
    while(i >= 0 && A[i] >= A[i + 1])
        --i;
    if(i >= 0){
        int j = A.size() - 1;
        while(j >= 0 && A[j] <= A[i])
            --j;
        swap(A[i], A[j]);
    }
    else return false;
    reverse(A.begin() + i + 1, A.end());
    return true;
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    
    do {
        ans.push_back(A);
    } while(nextPermutation(A));
    
    return ans;
}
