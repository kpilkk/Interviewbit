// https://www.interviewbit.com/problems/rotated-array/

// 1st solution
int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return -1;
      
    if(n == 1)
        return A[0];
    
    int l = 0, r = n - 1;
    if(A[l] < A[r])
        return A[l];
        
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(A[mid] > A[mid + 1])
            return A[mid + 1];
        if(A[mid - 1] > A[mid])
            return A[mid];
        if(A[l] < A[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}


// 2nd solution
int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    
    int i=0, j=n-1;
    
    while(A[i]>A[j]){
        int mid = i + (j-i)/2;
        if(A[mid]>=A[i])
            i = mid+1;
        else if(A[mid<A[j]])
            j = mid;
    }
    return A[i];
}
