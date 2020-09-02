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

// Recursion

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

// Morris Traversal

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    
    TreeNode* pre = NULL;
    while(A != NULL){
        if(A->left == NULL){
            ans.push_back(A->val);
            A = A->right;
        }
        else{
            pre = A->left;
            while(pre->right != NULL && pre->right != A){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = A;
                A = A->left;
            }
            else{
                pre->right = NULL;
                ans.push_back(A->val);
                A = A->right;
            }
        }
    }
    return ans;
}

// Uisng Stack

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> temp;
    
    while(A || !temp.empty()){
        while(A){
            temp.emplace(A);
            A = A->left;
        }
        A = temp.top();
        temp.pop();
        ans.push_back(A->val);
        A = A->right;
    }
    return ans;
}
