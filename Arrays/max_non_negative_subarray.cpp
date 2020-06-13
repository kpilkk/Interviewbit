// https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    long long sum = 0;
    long long max_sum = -1;

    int left = -1;
    int right = 0;
    int i=0;
    while(i<n){
        int temp = i;
        
        while(A[i]>=0 && i<n){
            sum += A[i++];
        }

        if(sum>max_sum){
            max_sum = sum;
            left = temp;
            right = i;
        }
        else if(sum==max_sum){
            if(i-temp>right-left){
                left = temp;
                right = i;
            }
        }

        while(A[i]<0 && i<n)
            ++i;

        sum = 0;
    }
    
    vector<int> ans(A.begin()+left, A.begin()+right);
    return ans;
}
