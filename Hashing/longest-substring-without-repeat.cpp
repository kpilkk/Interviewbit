// https://www.interviewbit.com/problems/longest-substring-without-repeat/

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
