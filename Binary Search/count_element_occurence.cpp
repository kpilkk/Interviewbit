// https://www.interviewbit.com/problems/count-element-occurence/

// Using binary search
int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();

    int i = 0;
    int j = n-1;
    
    int count = 0;
    int mid_ = -1;
    while(i<=j){
        // i<=j is placed as it will fail for the case when n=1 and the B=A[0]
        // A : [ 1 ]  B : 1
        int mid = i+(j-i)/2;
        if(A[mid]==B){
            mid_ = mid;
            break;
        }
        else if(A[mid]<B)
            i = mid+1;
        else
            j = mid-1;
    }
    
    if(mid_==-1) return 0;
    
    for(int i=mid_;i<n;++i){
        if(A[i]==B) ++count;
        else break;
    }
    for(int i=mid_-1;i>=0;--i){
        if(A[i]==B) ++count;
        else break;
    }
    return count;
}

