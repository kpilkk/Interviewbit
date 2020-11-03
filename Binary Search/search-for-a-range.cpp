// https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    vector<int> ans(2, -1);
    if(A.empty())
        return ans;
    
    int l = 0, r = n - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(A[mid] < B)
            l = mid + 1;
        else
            r = mid;
    }
    if(A[l] != B)
        return ans;
    ans[0] = l;
    
    r = n - 1;
    while(l < r){
        int mid = (l + r) / 2 + 1;
        if(A[mid] > B)
            r = mid - 1;
        else
            l = mid;
    }
    ans[1] = r;
    
    return ans;
}
