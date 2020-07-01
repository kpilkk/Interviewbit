// https://www.interviewbit.com/problems/count-element-occurence/

// Using binary search
int Solution::findCount(const vector<int> &A, int B) {
    int count = 0;
    int n = A.size();
    int l=0, r=n-1;
    int x = -1;

    while(l<=r){
        int mid = l+(r-l)/2;
        if(A[mid]==B){
            x = mid;
            break;
        }
        if(A[mid]<B) l=mid+1;
        else r=mid-1;
    }
    
    if(x!=-1){
        int i = x;
        while(A[i]==B && i>=0){
            ++count;
            --i;
        }
        i = x+1;
        while(A[i]==B && i<n){
            ++count;
            ++i;
        }
    }
    return count;
}
