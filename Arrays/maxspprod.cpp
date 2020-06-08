// https://www.interviewbit.com/problems/maxspprod/?ref=similar_problems

// My solution : time limit exceeded

int leftspecialvalue(vector<int> &A, int i){
    if(i==0) return 0;
    int val = 0;
    for(int j=i-1;j>=0;--j){
        if(A[j]>A[i]){
            val = j;
            break;
        }
    }
    return val;
}

int rightspecialvalue(vector<int> &A, int i){
    if(i==A.size()) return 0;
    int val = 0;
    for(int j=i+1;j<A.size();++j){
        if(A[j]>A[i]){
            val = j;
            break;
        }
    }
    return val;   
}

int Solution::maxSpecialProduct(vector<int> &A) {
    int mod = 1000000007;
    int ans = 0;
    
    for(int i=0;i<A.size();++i){
        // cout << ans << " ";
        ans = max(leftspecialvalue(A,i)*rightspecialvalue(A,i), ans);
    }
    
    return ans%mod;
}

// solution using next greater element which makes use of stack
int Solution::maxSpecialProduct(vector<int> &A) {
    int mod = 1000000007;
    long long int ans = 0;
    
    int n = A.size();
    vector<long long> left(n), right(n);
    
    stack<pair<int,int>> s;
    
    for(int i=0;i<n;++i){
        while(!s.empty() && s.top().first<=A[i])
            s.pop();
            
        if(s.empty())
            left[i] = 0;
        else
            left[i] = s.top().second;
            
        s.push({A[i], i});
    }
    
    while(!s.empty())
        s.pop();
        
    for(int i=n-1;i>=0;--i){
        while(!s.empty() && s.top().first<=A[i])
            s.pop();
            
        if(s.empty())
            right[i] = 0;
        else
            right[i] = s.top().second;
            
        s.push({A[i], i});
    }
    
    for(int i=0;i<n;++i){
        ans = max(ans, left[i]*right[i]);
    }
    return ans%mod;
}
