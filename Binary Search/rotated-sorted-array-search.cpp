// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int l = 0, r = n - 1;
    
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(A[mid] == B)
            return mid;
        if(A[l] <= A[mid]){
            if(A[l] <= B && A[mid] >= B)
                r = mid;
            else
                l = mid + 1;
        }
        else{
            if(A[mid] <= B && A[r] >= B)
                l = mid;
            else
                r = mid - 1;
        }
    }
    return -1;
}
