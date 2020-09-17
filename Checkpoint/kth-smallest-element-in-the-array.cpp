// https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());

    for(int i = 0; i < B - 1; ++i)
        pq.pop();

    return pq.top();
}
