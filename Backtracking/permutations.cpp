// https://www.interviewbit.com/problems/permutations/

// recursive solution
void permuteUnique(vector<int> A, int i,vector<vector<int>>& ans){
    if(i==A.size())
        ans.push_back(A);
    else{
        for(int j=i;j<A.size();++j){
            swap(A[i],A[j]);
            permuteUnique(A, i+1, ans);
	    // I've commented below swap because I'm not changing nums from original
            // Because I've not used address of the vector
            // swap(A[i], A[j]);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    permuteUnique(A, 0, ans);
    return ans;
}

// non-recursive solution

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
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    do{
        ans.push_back(A);
    } while(nextPermutation(A));
    
    return ans;
}
