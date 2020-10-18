// https://www.interviewbit.com/problems/letter-phone/

// Backtracking solution
vector<string> phone = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(vector<string>& ans, string combination, string next_digits){
    if(next_digits.length() == 0)
        ans.push_back(combination);
    else{
        string letters = phone[next_digits[0] - '0'];
        for(int i = 0; i < letters.length(); ++i){
            string letter = letters.substr(i, 1);
            backtrack(ans, combination + letter, next_digits.substr(1));
        }
    }
}
vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    if(A.length() != 0)
        backtrack(ans, "", A);
    return ans;
}
