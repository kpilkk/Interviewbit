// https://www.interviewbit.com/problems/sort-by-color/

// Accepted solution
void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int zero = 0, one = 0;
    int n = A.size();
    for(int i=0;i<n;++i){
        if(A[i]==0) ++zero;
        if(A[i]==1) ++one;
    }
    for(int i=0;i<zero;++i){
        A[i] = 0;
    }
    for(int i=zero;i<zero+one;++i){
        A[i] = 1;
    }
    for(int i=zero+one;i<n;++i){
        A[i] = 2;
    }
}
