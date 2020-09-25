// https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int left = 0, right = 0, ans = 0, sum = 0;
    
    while(right < n){
        if(sum + A[right] < B){
            sum += A[right++];
            ans += (right - left);
        }
        else{
            sum -= A[left++];
        }
    }
    return ans;
}

// GFG based solution 

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int left = 0, right = 0, ans = 0, sum = A[0];

    while(left < n && right < n){
        if(sum < B){
            ++right;

            if(left <= right);
                ans += (right - left);

            if(right < n)
                sum += A[right];
        }

        else{
            sum -= A[left++];
        }
    }
    return ans;
}
