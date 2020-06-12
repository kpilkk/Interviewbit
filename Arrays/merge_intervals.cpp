// https://www.interviewbit.com/problems/merge-intervals/

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
     return a.start < b.start;
 }
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), compare);
    
    int n = intervals.size();
    
    if(n==1) return intervals;
    
    vector<Interval> ans;
    
    ans.push_back(intervals[0]);
    
    for(int i=1;i<n;++i){
        if(intervals[i].start<=ans[ans.size()-1].end)
            ans[ans.size()-1].end = max(ans[ans.size()-1].end, intervals[i].end);
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
