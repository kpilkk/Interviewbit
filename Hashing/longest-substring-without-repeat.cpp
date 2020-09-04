// https://www.interviewbit.com/problems/longest-substring-without-repeat/

// 1st solution
int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length();
    int i = 0, j = 0, ans = 0;
    set<int> temp;
    
    while(i < n && j < n){
        if(temp.find(A[j]) == temp.end()){
            temp.emplace(A[j++]);
            ans = max(ans, j - i);
        }
        else{
            temp.erase(A[i++]);
        }
    }
    return ans;
}


// Most optimized solution

int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length(), ans = 0;
    map<char, int> temp;
    
    for(int i = 0, j = 0; j < n; ++j) {
        if(temp.find(A[j]) != temp.end()) {
            i = max(i, temp[A[j]]);
        }
        ans = max(ans, j - i + 1);
        temp[A[j]] = j + 1;
    }
    return ans;
}
