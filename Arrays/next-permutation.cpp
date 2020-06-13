// https://www.interviewbit.com/problems/next-permutation/

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
