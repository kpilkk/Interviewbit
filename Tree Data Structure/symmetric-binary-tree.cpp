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
