// https://www.interviewbit.com/problems/rearrange-array/

// Acceptable solution
// idea is to store two numbers in one number
void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    
    for(int i=0;i<n;++i){
        A[i] = (A[i]%n)+(A[A[i]]%n)*n;
    }
    
    for(int i=0;i<n;++i){
        A[i] /= n;
    }
}

// using extra memory - not accepted in real programming
void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<int> ans(n);
    
    for(int i=0;i<n;++i)
        ans[i] = A[A[i]];
    
    for(int i=0;i<n;++i)
        A[i] = ans[i];
}
