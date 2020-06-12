// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long sum = 0;
    long long square_sum = 0;
    
    for(int i=0;i<n;++i){
        sum = sum+A[i]-i-1;
        square_sum = square_sum + (long long)A[i]*A[i] - (long long)(i+1)*(i+1);
    }
    
    square_sum = square_sum/sum;
    
    vector<int> ans;
    ans.push_back(((long long)sum+square_sum)/2);
    ans.push_back(((long long)square_sum-sum)/2);
    return ans;
}
