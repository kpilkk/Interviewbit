// problem link: https://www.interviewbit.com/problems/find-permutation/

// Using stack
vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    if(n==0) return {1};

    vector<int> ans;
    stack<int> s;
    
    int j = 1;
    for(int i=0;i<n;++i){
        if(A[i]=='I'){
            s.push(j++);
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
        else{
            s.push(j++);
        }
    }
    s.push(j);
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Solution by reversing the subarray
vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    vector<int> res(n+1);
    for(int i=1;i<=n+1;++i)
        res[i-1] = i;
    
    int i = 0;
    while(i<n){
        if(A[i]=='I') ++i;
        else{
            int j = i;
            while(i<n && A[i]=='D') ++i;
            reverse(res.begin()+j, res.begin()+i+1);
        }
    }
    return res;
}
