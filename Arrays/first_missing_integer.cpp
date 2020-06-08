// https://www.interviewbit.com/problems/first-missing-integer/

// Memory limit exceeded

int Solution::firstMissingPositive(vector<int> &A) {
    // int mini = 1;
    int maxi = 1;
    
    for(int i=0;i<A.size();++i){
        if(A[i]>0){
            // mini = min(A[i], mini);
            maxi = max(A[i], maxi);
        }
    }
    // if(maxi==1) return 1;
    
    unordered_set<int> s;
    for(int i=0;i<A.size();++i){
        s.insert(A[i]);
    }
    
    for(int i=0;i<A.size();++i){
        if(s.find(i+1)==s.end()){
            return i+1;
        }
    }
    return maxi+1;
}

// Acceptable solution
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    vector<bool> temp(n);
    
    for(int i=0;i<n;++i){
        // Array may contain the value greater than n, which will cause run-time error
        if(A[i]>0 && A[i]<=n){
            temp[A[i]-1] = true;
        }
    }
    
    for(int i=0;i<n;++i){
        if(temp[i]==false)
            return i+1;
    }
    return n+1; // if all numbers between given range exists
}
