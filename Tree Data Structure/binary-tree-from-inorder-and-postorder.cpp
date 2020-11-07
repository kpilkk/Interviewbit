// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

// Recursive solution
TreeNode* helper(vector<int>& inorder, int i, int m, vector<int>& postorder, int j, int n){
    if(i == m || j == n)
        return nullptr;
    
    int mid = find(inorder.begin() + i, inorder.begin() + m, postorder[n - 1]) - inorder.begin();
    
    TreeNode* root = new TreeNode(postorder[n - 1]);
    
    root -> left = helper(inorder, i, mid, postorder, j, j + mid - i); // distance of mid - i from j
    root -> right = helper(inorder, mid + 1, m, postorder, j + mid - i, n - 1);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return helper(A , 0, A.size(), B, 0, B.size());
}
