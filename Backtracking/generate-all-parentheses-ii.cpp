// https://www.interviewbit.com/problems/generate-all-parentheses-ii/

// Backtracking solution
void backtrack(vector<string>& ans, string cur, int open, int close, int max){
    if(cur.length() == max * 2){
        ans.push_back(cur);
        return;
    }
    
    if(open < max)
        backtrack(ans, cur + "(", open + 1, close, max);
    if(close < open)
        backtrack(ans, cur + ")", open, close + 1, max);
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    backtrack(ans, "", 0, 0, A);
    return ans;
}
