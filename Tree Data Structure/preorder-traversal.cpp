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
