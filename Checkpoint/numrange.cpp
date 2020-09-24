// https://www.interviewbit.com/problems/numrange/

int countLess(vector<int> A, int x){
    int n = A.size();
    int i = 0, j = 0, sum = 0, ans = 0;
    
    while(j < n){
        sum += A[j];
        
        while(i <= j && sum > x){
            sum -= A[i++];
        }
        
        ans += (j - i + 1);
        j++;
    }
    return ans;
}
int Solution::numRange(vector<int> &A, int B, int C) {
    int lCnt = countLess(A, B - 1);
    int rCnt = countLess(A, C);
    
    return rCnt - lCnt;
}
