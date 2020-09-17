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

// optimized to find turning point

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

    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (r - l) / 2 + l;
        if(A[mid] > A[mid - 1] && A[mid] < A[mid + 1])
            l = mid + 1;
        else if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1]){
            l = mid + 1;
            break;
        }
        else 
            r = mid - 1;
    }

    int ans = binarySearch(A, 0, l, B);
    if(ans == -1)
        ans = binarySearch1(A, l, n, B);
        
    return ans;
}
