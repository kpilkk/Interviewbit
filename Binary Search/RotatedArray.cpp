// https://www.interviewbit.com/problems/rotated-array/

// 1st solution
int Solution::findMin(const vector<int> &A) {
    int l=0, r=A.size()-1;
    while(l<=r){
        if(A[r]>=A[l]) 
          return A[l];
        int mid = l+(r-l)/2;
        int next = (mid + 1), prev = (mid - 1);
        
        if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
          return A[mid];
        else if(A[mid] <= A[r]) // Case 3
          r = mid - 1; 
        else if(A[mid] >= A[l]) 
          l = mid + 1; // Case 4
    }
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
