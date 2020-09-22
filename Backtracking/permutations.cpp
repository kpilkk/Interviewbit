// https://www.interviewbit.com/problems/permutations/

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
