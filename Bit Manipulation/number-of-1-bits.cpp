// https://www.interviewbit.com/problems/number-of-1-bits/

// 1st solution

int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans = 0;
    while(A){
        A = A & (A - 1);
        ans++;
    }
    return ans;
}


// 2nd solution

int Solution::numSetBits(unsigned int A) {
    int count = 0;
    while(A){
        if(A&1)
            ++count;

        A>>=1;
    }    
    return count;
}

