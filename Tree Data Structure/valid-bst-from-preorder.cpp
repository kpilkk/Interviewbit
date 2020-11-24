// https://www.interviewbit.com/problems/valid-bst-from-preorder/

// Using stack
int Solution::solve(vector<int> &pre) {
    stack<int> s;
    int root = INT_MIN;
    
    for(int i =0;i<pre.size();i++){
        if(root > pre[i]){
            return 0;
        }
        while(!s.empty() && s.top()<pre[i]){
           root = s.top();
           s.pop();
        }
        s.push(pre[i]);
    }
    return 1;
}
