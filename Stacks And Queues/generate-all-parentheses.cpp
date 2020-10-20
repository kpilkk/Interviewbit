// https://www.interviewbit.com/problems/generate-all-parentheses/

int Solution::isValid(string A) {
    int n = A.length();
    if(n % 2 != 0)
        return false;
        
    stack<char> temp;
    for(int i = 0; i < n; ++i){
        if(A[i] == '(' || A[i] == '{' || A[i] == '[')
            temp.push(A[i]);
        else if(!temp.empty()){
            char tmp = temp.top();
            temp.pop();
            if((A[i] == ')' && tmp != '(') || (A[i] == ']' && tmp != '[') || (A[i] == '{' && tmp != '}'))
                return false;
        }
        else
            return false;
    }
    return temp.empty();
}
