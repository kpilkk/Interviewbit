/*
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

	1.Length of given string s will always equal to n - 1
	2.Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]
*/

// Solution using stack
vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    vector<int> ans(n+1);
    stack<int> s;
    int j = 0;
    for(int i=1;i<=n;++i){
        if(A[i-1]=='I'){
            s.push(i);
            while(!s.empty()){
                ans[j++] = s.top();
                s.pop();
            }
        }
        else{
            s.push(i);
        }
    }
    s.push(n+1);
    while(!s.empty()){
        ans[j++] = s.top();
        s.pop();
    }
    return ans;
}