// https://www.interviewbit.com/problems/path-sum/

// Recursive solution
int Solution::hasPathSum(TreeNode* A, int B) {
    if(!A)
        return 0;
    
    if(A -> left == A -> right)
        return B == A -> val;
    
    return hasPathSum(A -> left, B - A -> val) || hasPathSum(A -> right, B - A -> val);
}
