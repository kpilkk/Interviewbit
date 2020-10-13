// https://www.interviewbit.com/problems/3-sum/

// Two pointer
int Solution::threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    long long diff = A[0] + A[1] + A[2];
    sort(A.begin(), A.end());
    for(int i = 0; i < n; ++i){
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            long long sum = 0LL + A[i] + A[l] + A[r];
            if(abs(sum - B) < abs(B - diff))
                diff = sum;
            if(sum == B)
                return sum;
            else if(sum > B)
                --r;
            else
                ++l;
        }
    }
    return diff;
}
