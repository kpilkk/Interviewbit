// https://www.interviewbit.com/problems/nextgreater/

vector<int> Solution::nextGreater(vector<int> &A) {
    if(A.size()==0) return A;
    if(A.size()==1) return {-1};
    
    int n = A.size();
    vector<int> ans(n);
    
    stack<int> s;
    
    // s.push(A[0]);
    
    for(int i=n-1;i>=0;--i){
        while(!s.empty() && s.top()<=A[i]){
            s.pop();
        }
        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        
        s.push(A[i]);
    }
    return ans;
}
