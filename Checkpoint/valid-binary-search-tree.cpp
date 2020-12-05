// https://www.interviewbit.com/problems/valid-binary-search-tree/

// Recursive solution
bool helper(TreeNode* A, int lower, int upper){
    if(!A)
        return true;
    int val = A -> val;
    if(lower && val <= lower)
        return false;
    if(upper && val >= upper)
        return false;
    if(!helper(A -> left, lower, val))
        return false;
    if(!helper(A -> right, val, upper))
        return false;
    
    return true;
}

int Solution::isValidBST(TreeNode* A) {
    return helper(A, NULL, NULL);
}

// Iterative solution using stack
int Solution::isValidBST(TreeNode* A) {
    if(!A)
        return true;
    stack<TreeNode*> stack;
    TreeNode* pre = nullptr;
    while(A || !stack.empty()){
        while(A){
            stack.emplace(A);
            A = A -> left;
        }
        A = stack.top();
        stack.pop();
        if(pre && A -> val <= pre -> val)
            return false;
        pre = A;
        A = A -> right;
    }
    return true;
}
