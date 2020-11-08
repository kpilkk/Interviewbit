// https://www.interviewbit.com/problems/preorder-traversal/

// Recursive solution
void helper(TreeNode* root, vector<int>& ans){
    if(!root)
        return;
    ans.emplace_back(root -> val);
    helper(root -> left, ans);
    helper(root -> right, ans);
} 

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    helper(A, ans);
    return ans;
}

// Iterative solution using stack
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> stack;
    
    while(A || !stack.empty()){
        if(A){
            ans.emplace_back(A -> val);
            if(A -> right)
                stack.emplace(A -> right);
            A = A -> left;
        }
        else{
            A = stack.top();
            stack.pop();
        }
    }
    
    return ans;
}

// Morris traversal
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    
    while(A){
        if(A -> left){
            TreeNode* pre = A -> left;
            while(pre -> right && pre -> right != A)
                pre = pre -> right;
            if(pre -> right){
                pre -> right = nullptr;
                A = A -> right;
            }
            else{
                pre -> right = A;
                ans.emplace_back(A -> val);
                A = A -> left;
            }
        }
        else{
            ans.emplace_back(A -> val);
            A = A -> right;
        }
    }
    
    return ans;
}
