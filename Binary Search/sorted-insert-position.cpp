// https://www.interviewbit.com/problems/sorted-insert-position/

// Binary Search
int Solution::searchInsert(vector<int> &A, int B) {
    int l = 0, r = A.size() - 1;
    // return lower_bound(A.begin(), A.end(), B) - A.begin();
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(A[mid] == B)
            return mid;
        if(A[mid] > B)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
