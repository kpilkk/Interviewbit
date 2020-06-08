// https://www.interviewbit.com/problems/merge-overlapping-intervals/

// 1st solution
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(Interval a, Interval b){
     return a.start<b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    sort(A.begin(), A.end(), compare);
    
    // exception
    if(n==0 || n==1) return A;
    
    vector<Interval> ans;
    ans.push_back(A[0]);
    
    for(int i=1;i<n;++i){
        if(A[i].start<=ans[ans.size()-1].end){
            ans[ans.size()-1].end = max(ans[ans.size()-1].end, A[i].end);
        }
        else
            ans.push_back(A[i]);
    }
    return ans;
}

// 2nd solution

bool compare(Interval a, Interval b){
    return (a.start < b.start);
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), compare);
    
    // auto it = A.begin();
    int i = 0;
    for(int j=1;j<A.size();++j){
        if(A[i].end>=A[j].start)
            A[i].end = max(A[i].end, A[j].end);
        else{
            ++i;
            A[i].start = A[j].start;
            A[i].end = A[j].end;
        }
    }
    A.erase(A.begin()+i+1, A.end());
    return A;
}
