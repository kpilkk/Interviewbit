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

// Backtrack solution

void permute_recurse(vector<vector<int>>& ans, vector<int> A, int i){
    if(i == A.size())
        ans.push_back(A);
        
    else{
        for(int j = i; j < A.size(); ++j){
            if(i == j || A[j] != A[i]){
                swap(A[i], A[j]);
                permute_recurse(ans, A, i + 1);
            }
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    permute_recurse(ans, A, 0);
    return ans;
}
