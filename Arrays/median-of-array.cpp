// https://www.interviewbit.com/problems/median-of-array/

// Binary search method

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size(), n = B.size();
    if(m > n)
        return findMedianSortedArrays(B, A);
        
    int l = 0, r = m;
    
    while(l <= r){
        int i = (l + r) / 2, j = (m + n + 1) / 2 - i;
        if(i && A[i - 1] > B[j])
            r = i - 1;
        else if(i < m && B[j - 1] > A[i])
            l = i + 1;
        else{
            int lmax = !i ? B[j - 1] : (!j ? A[i - 1] : max(A[i - 1], B[j - 1]));
            if((m + n) % 2)
                return lmax;
            int rmin = i == m ? B[j] : (j == n ? A[i] : min(A[i], B[j]));
            return 0.5 * (lmax + rmin);
        }
    }
    return 0.0;
}


// Simple solution, but TLE on Interviewbit



double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m = A.size(), n = B.size();
    int target = (m + n);
    int i = 0, j = 0, count = 0, prev = 0;

    while(true) {
        int ans = 0;

        int x = INT_MAX;
        int y = INT_MAX;

        if(i < m) x = A[i];
        if(j < n) y = B[j];

        if(x == INT_MAX && y == INT_MAX) break;

        if(x < y) {
            ans = x;
            i++;
        }
        else{
            ans = y;
            j++;
        }

        if(count == target / 2){
            if(target % 2 != 0)
                return ans;
            else
                return double(prev + ans) / 2;
        }
        prev = ans;
        count++;
    }
    return 0;
}
