// https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string A, int B) {
    vector<string> temp(B);
    int n = A.length();
    int i = 0;
    while(i < n){
        for(int j = 0; j < B && i < n; ++j)
            temp[j].push_back(A[i++]);
        for(int j = B - 2; j > 0 && i < n; --j)
            temp[j].push_back(A[i++]);
    }
    string ans;
    for(int i = 0; i < B; ++i)
        ans += temp[i];
    return ans;
}
