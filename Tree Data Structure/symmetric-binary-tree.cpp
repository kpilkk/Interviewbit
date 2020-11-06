// https://www.interviewbit.com/problems/symmetric-binary-tree/

// Recursive solution
int isMirror(TreeNode* left, TreeNode* right){
    if(!left && !right)
        return true;
    if(!left || !right)
        return false;
    
    return (left -> val == right -> val) && isMirror(left -> left, right -> right) && isMirror(left  -> right, right -> left);
}
int Solution::isSymmetric(TreeNode* A) {
    return isMirror(A , A);
}

// BFS iterative solution
int Solution::isSymmetric(TreeNode* A) {
    if(!A)
        return 1;
    queue<TreeNode*> bfs;
    bfs.push(A);
    bfs.push(A);
    while(!bfs.empty()){
        auto left = bfs.front();
        bfs.pop();
        auto right = bfs.front();
        bfs.pop();
        if(!left && !right)
            continue;
        if(!left|| !right)
            return 0;
        if(left -> val != right -> val)
            return false;
        bfs.push(left -> left);
        bfs.push(right -> right);
        bfs.push(left -> right);
        bfs.push(right  -> left);
    }
    return 1;
}
