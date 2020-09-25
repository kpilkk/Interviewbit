// https://www.interviewbit.com/problems/numrange/

// Using sum less than k problem
int countLess(vector<int> A, int x){
    int i = 0, j = 0, sum = 0, count = 0;
    int n = A.size();
    
    while(j < n && i < n){
        if(sum + A[j] < x){
            sum += A[j++];
            count += (j - i);
        }
        else{
            sum -= A[i++];
        }
    }
    return count;
}
int Solution::numRange(vector<int> &A, int B, int C) {
    return countLess(A, C + 1) - countLess(A, B);
}

// Using two pointer

int Solution::numRange(vector<int> &A, int B, int C) {
    int n = A.size();
    int i = 0, j = 0, sum = 0, ans = 0;
    while(i < n){
        sum += A[j];
        if(sum >= B && sum <= C){
            ans++;
            j++;
        }
        else if(sum < B){
            j++;
        }
        else if(sum > C){
            i++;
            j = i;
            sum = 0;
        }
        if(j == n){
            sum = 0;
            i++;
            j = i;
        }
    }
        
    return ans;
}

// Brute force(Accepted)

int Solution::numRange(vector<int> &A, int B, int C) {
    int n = A.size(), ans = 0;
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = i; j < n; ++j){
            sum += A[j];
            if(sum >= B && sum <= C)
                ++ans;
            if(sum > C)
                break;
        }
    }
    return ans;
}
