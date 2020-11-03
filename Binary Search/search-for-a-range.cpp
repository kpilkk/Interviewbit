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

// Divide and conquer solution
vector<int> search(const vector<int> &nums, int l, int r, int target){
    if(nums[l] == target && nums[r] == target)
        return {l, r};
    if(nums[l] <= target && target <= nums[r]){
        int mid = l + ((r - l) >> 1);
        vector<int> left = search(nums , l, mid, target);
        vector<int> right = search(nums , mid + 1, r, target);
        if(left[0] == -1)
            return right;
        if(right[0] == -1)
            return left;
        return {left[0], right[1]};
    }
    return {-1 , -1};
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    return search(A, 0, n - 1, B);
}
