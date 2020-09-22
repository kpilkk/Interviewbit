// https://www.interviewbit.com/problems/next-permutation/

// Consice solution
vector<int> Solution::nextPermutation(vector<int> &A) {
    int i = A.size() - 2;
    while(i >= 0 && A[i] >= A[i + 1])
        --i;
    
    if(i >= 0){
        int j;
        for(j = A.size() - 1; j >= 0; --j){
            if(A[j] > A[i])
                break;
        }
        swap(A[i], A[j]);
    }
    reverse(A.begin() + i + 1, A.end());
    return A;
}

// simple of the above
vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    if(n==0 || n==1) return A;
    
    int num = -1;
    int i=-1;
    for(i=n-2;i>=0;--i){
        if(A[i]<A[i+1]){
            num = i;
            break;
        }
    }

    if(num==-1){
        reverse(A.begin(), A.end());
    }
    else{
        int mini = num;
        for(i=n-1;i>num;--i){
            if(A[i]>A[mini]){
                mini = i;
                break;;
            }
        }
        swap(A[mini], A[num]);
        reverse(A.begin()+num+1, A.end());
    }
    return A;
}
