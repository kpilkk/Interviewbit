// https://leetcode.com/problems/longest-consecutive-sequence/

int Solution::longestConsecutive(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    unordered_set<int> s(A.begin(), A.end());
    int ans = 1;
    for(int i = 0; i < n; ++i){
        // INT_MIN and INT_MAX conditions are given for some testcases
        // like 2 2147483647 -2147483648 or 2 -2147483647 -2147483648
        if((A[i] == INT_MAX || s.find(A[i] + 1) == s.end()) && A[i] != INT_MIN){
            int len = 1, temp = A[i] - 1;
            while(s.find(temp) != s.end()){
                ++len;
                if(temp == INT_MIN)
                    break;
                --temp;
            }
            ans = max(ans, len);
        }
    }
    return ans;
}
