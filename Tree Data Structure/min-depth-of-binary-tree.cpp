// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

// DFS recursive solution
int Solution::minDepth(TreeNode* A) {
    if(!A)
        return 0;
    
    if(!A -> left)
        return 1 + minDepth(A -> right);
    if(!A -> right)
        return 1 + minDepth(A -> left);
        
    return 1 + min(minDepth(A -> left), minDepth(A -> right));
}

// BFS iterative solution
int Solution::minDepth(TreeNode* A) {
    if(!A)
        return 0;
        
    queue<TreeNode*> bfs;
    bfs.push(A);
    int ans = 0;
    
    while(!bfs.empty()){
        int n = bfs.size();
        ++ans;
        for(int i = 0; i < n; ++i){
            TreeNode* temp = bfs.front();
            bfs.pop();
            if(temp -> left == temp -> right)
                return ans;
            if(temp -> left)
                bfs.push(temp -> left);
            if(temp -> right)
                bfs.push(temp -> right);
        }
    }
    return ans;
}
