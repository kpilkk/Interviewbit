// https://www.interviewbit.com/problems/search-in-bitonic-array/

// Accepted solution

int binarySearch(vector<int> A, int i, int j, int B){
    int l = i, r = j - 1;
    while(l <= r){
        int mid = (r - l) / 2 + l;
        if(A[mid] == B)
            return mid;
        else if(A[mid] > B)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int binarySearch1(vector<int> A, int i, int j, int B){
    int l = i, r = j - 1;
    while(l <= r){
        int mid = (r - l) / 2 + l;
        if(A[mid] == B)
            return mid;
        else if(A[mid] > B)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int index = 0;
    for(int i = 1; i < n; ++i){
        if(A[i - 1] > A[i]){
            index = i;
            break;
        }
    }
    
    int ans = binarySearch(A, 0, index, B);
    if(ans == -1)
        ans = binarySearch1(A, index, n, B);
        
    return ans;
}

// Interviewbit solution



int Solution::solve(vector<int> &A, int B) {
    // First finding turning point in O(logn)
    // then finding in 0 to turning point and turning point to n
    
    int low=0;
    int high=A.size()-1;
    int mid;
    while(low<high)    //finding turning point
    {
        mid=(low+high)/2;
        if(A[mid]>A[mid-1] && A[mid]<A[mid+1])
            low=mid+1;
        else if(A[mid]>A[mid-1] && A[mid]>A[mid+1]){
            low=mid;high=mid;}
        else
            high=mid;
    }
    
    int bt=low;
    int l=0,h=bt;
    while(l<h)     // finding value between 0 and turning point
    {
        mid=(l+h)/2;
        if(A[mid]<B)
            l=mid+1;
        else
            h=mid;
    }
    if(A[l]!=B)
    {
        l=bt;
        h=A.size()-1;
        while(l<h)    // finding value between turning point and last point
        {
            mid=(l+h)/2;
            if(A[mid]>B)
                l=mid+1;
            else
                h=mid;
        }
    }
    if(A[l]!=B)
        return -1;
    else 
        return l;
}
