// https://www.interviewbit.com/problems/path-sum/

// Recursive solution
int Solution::hasPathSum(TreeNode* A, int B) {
    if(!A)
        return 0;
    
    if(A -> left == A -> right)
        return B == A -> val;
    
    return hasPathSum(A -> left, B - A -> val) || hasPathSum(A -> right, B - A -> val);
}

// BFS iterative solution
int Solution::hasPathSum(TreeNode* A, int B) {
    if(!A)
        return false;
    
    queue<pair<TreeNode*, int>> bfs;
    bfs.push({A, 0});
    while(!bfs.empty()){
        auto temp = bfs.front();
        bfs.pop();
        int s = temp.first -> val + temp.second;
        if(temp.first -> left == temp.first -> right && s == B)
            return 1;
        if(temp.first -> left)
            bfs.push({temp.first -> left, s});
        if(temp.first -> right)
            bfs.push({temp.first -> right, s});
    }
    return 0;
}
