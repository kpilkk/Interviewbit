// https://www.interviewbit.com/problems/postorder-traversal/

// Recursive solution
void helper(TreeNode* A, vector<int>& ans){
    if(!A)
        return;
    helper(A -> left, ans);
    helper(A -> right, ans);
    ans.emplace_back(A -> val);
}

vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    helper(A, ans);
    return ans;
}

// Iterative solution using stack
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> stack;
    TreeNode* last = nullptr;
    while(A || !stack.empty()){
        while(A){
            stack.emplace(A);
            A = A -> left;
        }
        TreeNode* temp = stack.top();
        if(temp -> right && temp -> right != last)
            A = temp -> right;
        else{
            stack.pop();
            ans.emplace_back(temp -> val);
            last = temp;
        }
    }
    return ans;
}
