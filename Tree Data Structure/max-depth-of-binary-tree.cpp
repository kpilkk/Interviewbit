// https://www.interviewbit.com/problems/max-depth-of-binary-tree/

// DFS recursive
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* A) {
    if(!A)
        return 0;
        
    return 1 + max(maxDepth(A -> left), maxDepth(A -> right));
}

// BFS iterative
int Solution::maxDepth(TreeNode* A) {
    if(!A)
        return 0;
        
    queue<TreeNode*> bfs;
    bfs.push(A);
    int ans = 0;
    
    while(!bfs.empty()){
        ++ans;
        int n = bfs.size();
        for(int i = 0; i < n; ++i){
            TreeNode* temp = bfs.front();
            bfs.pop();
            if(temp -> left)
                bfs.push(temp -> left);
            if(temp -> right)
                bfs.push(temp -> right);
        }
    }
    return ans;
}
