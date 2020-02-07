/*
	Given a collection of numbers, return all possible permutations.
	
	Example:
	
	[1,2,3] will have the following permutations:
	
	[1,2,3]
	[1,3,2]
	[2,1,3] 
	[2,3,1] 
	[3,1,2] 
	[3,2,1]
	 NOTE
	No two entries in the permutation sequence should be the same.
	For the purpose of this problem, assume that all the numbers in the collection are unique.
	 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
	Example : next_permutations in C++ / itertools.permutations in python.
	If you do, we will disqualify your submission retroactively and give you penalty points.
*/

// question link: https://www.interviewbit.com/problems/permutations/
void permuteUnique(vector<int> A, int i,vector<vector<int>>& ans){
    if(i==A.size())
        ans.push_back(A);
    else{
        for(int j=i;j<A.size();++j){
            swap(A[i],A[j]);
            permuteUnique(A, i+1, ans);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    
    permuteUnique(A, 0, ans);
    return ans;
}