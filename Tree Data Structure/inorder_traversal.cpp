// https://www.interviewbit.com/problems/inorder-traversal/

// Using Recursion
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* A, vector<int>& ans){
    if(A!=NULL){
        inorder(A->left, ans);
        ans.push_back(A->val);
        inorder(A->right, ans);
    }
}

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    
    inorder(A, ans);
    return ans;
}
