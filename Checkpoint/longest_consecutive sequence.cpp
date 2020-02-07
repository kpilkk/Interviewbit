// problem link: https://www.interviewbit.com/problems/longest-consecutive-sequence/

// 1st solution
int Solution::longestConsecutive(const vector<int> &A) {
    vector<int> nums(A);
    int n = A.size();
    if(n==0) return 0;
    if(n==1) return 1;
    
    sort(nums.begin(), nums.end());
    int ans = 1;
    int count = 1;
    for(int i=0;i<n-1;++i){
    if(nums[i+1]-nums[i]==1)
        ++count;
    else if(nums[i+1]-nums[i]==0)
        continue;
    else{
        ans = max(count, ans);
        count = 1;
    }
    }
    ans = max(count, ans);
    return ans;
}

// 2nd solution

int Solution::longestConsecutive(const vector<int> &A) {
    int n = A.size();
    unordered_set<int> s;
    
    int ans = 0;
    for(int i=0;i<A.size();++i)
        s.insert(A[i]);
    
    for(int i=0;i<n;++i){
        if(s.find(A[i]-1)==s.end()){
            int j = A[i];
            while(s.find(j)!=s.end())
                ++j;
            ans = max(ans, j-A[i]);
        }
    }
    return ans;
}