// https://www.interviewbit.com/problems/find-duplicate-in-array/

// 1st solution
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    if(n==0 || n==1) return -1;
    
    // As there is one extra element, so there must be repitition
    int ans = 0;
    
    for(int i=0;i<n;++i){
        ans ^= A[i];
        ans ^= i;
    }
    return ans;
}




int Solution::repeatedNumber(const vector<int> &A) {
    // int n = A.size();

    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    slow = 0;
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }

    // if(slow==0) return -1;
    return slow;
}
