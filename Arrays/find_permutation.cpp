// problem link: https://www.interviewbit.com/problems/find-permutation/
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


// Solution by reversing the subarray
vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    vector<int> res(n+1);
    for(int i=1;i<=n+1;++i)
        res[i-1] = i;
    
    int i = 0;
    while(i<n){
        if(A[i]=='I') ++i;
        else{
            int j = i;
            while(i<n && A[i]=='D') ++i;
            reverse(res.begin()+j, res.begin()+i+1);
        }
    }
    return res;
}
