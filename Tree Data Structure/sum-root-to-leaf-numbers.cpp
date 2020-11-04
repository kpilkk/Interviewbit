// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

// DFS Recursion
void dfs(TreeNode* A, int val, int& ans){
    if(!A)
        return;
    val = (val * 10 + A -> val) % 1003;
    if(A -> left == A -> right)
        ans = (ans + val) % 1003;
    dfs(A -> left, val, ans);
    dfs(A -> right, val, ans);
}
int Solution::sumNumbers(TreeNode* A) {
    int ans = 0;
    dfs(A, 0, ans);
    return ans;
}

// BFS iteration
int Solution::sumNumbers(TreeNode* A) {
    if(!A)
        return 0;
    int ans = 0;
    queue<pair<TreeNode* , int>> bfs;
    bfs.push(make_pair(A, A -> val));
    pair<TreeNode*, int> curr;
    
    while(!bfs.empty()){
        curr = bfs.front();
        bfs.pop();
        
        if(curr.first -> left == curr.first -> right)
            ans = (ans + curr.second) % 1003;
            
        if(curr.first -> left)
            bfs.push(make_pair(curr.first -> left, (curr.second * 10 + curr.first -> left -> val) % 1003));
        if(curr.first -> right)
            bfs.push(make_pair(curr.first -> right, (curr.second * 10 + curr.first -> right -> val) % 1003));
    }
    return ans;
}
