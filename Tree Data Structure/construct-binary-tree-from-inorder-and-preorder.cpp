//  https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

// Recursive solution
TreeNode* helper(vector<int>& preorder, int i, int m, vector<int>& inorder, int j, int n){
    if(i == m || j == n)
        return nullptr;
    
    int mid = find(inorder.begin() + j, inorder.begin() + n, preorder[i]) - inorder.begin();
    
    TreeNode* root = new TreeNode(preorder[i]);
    
    root -> left = helper(preorder, i + 1, i + 1 + mid - j, inorder, j, mid);
    root -> right = helper(preorder, i + 1 + mid - j, m, inorder, mid + 1, n);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return helper(A , 0, A.size(), B, 0, B.size());
}
