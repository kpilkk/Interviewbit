// https://www.interviewbit.com/problems/count-element-occurence/

// Using binary search
int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    
    int i=0, j=n-1;
    while(i<j){
        int mid =i+(j-i)/2;
        if(A[mid]<B) i=mid+1;
        else j = mid;
    }
    if(A[i]!=B) return 0;
    int start = i;

    j = n-1;
    while(i<j){
        int mid = i+(j-i)/2+1; // biased to the right
        if(A[mid]>B) j = mid-1;
        else i = mid;  // / So that this won't make the search range stuck
    }
    int end = j;
    
    return end-start+1;
}
