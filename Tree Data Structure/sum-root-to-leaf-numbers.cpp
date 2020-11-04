// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

// DFS Recursion
void dfs(TreeNode* A, int val, int& ans){
    if(!A)
        return;
    val = (val * 10 + A -> val) % 1003;
    if(A -> left == A -> right)
        ans = (ans + val) % 1003;
    dfs(A -> left, val, ans);
    dfs(A -> right, val, ans);
}
int Solution::sumNumbers(TreeNode* A) {
    int ans = 0;
    dfs(A, 0, ans);
    return ans;
}
