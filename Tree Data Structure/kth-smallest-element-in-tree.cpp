// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

// Iterative solution using stack
// Similar to inorder traversal
int Solution::kthsmallest(TreeNode* A, int B) {
    stack<TreeNode*> stack;
    while(A || !stack.empty()){
        while(A){
            stack.emplace(A);
            A = A -> left;
        }
        A = stack.top();
        stack.pop();
        if(--B == 0)
            return A -> val;
        A = A -> right;
    }
}
