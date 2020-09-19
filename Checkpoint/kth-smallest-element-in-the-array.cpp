// https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

// Most efficient as vector is constant that means, extra memory use should be avoided
int Solution::kthsmallest(const vector<int> &A, int B) {
    int low = numeric_limits<int>::max();
    int high = numeric_limits<int>::min();
    
    for(auto a : A){
        low = min(low, a);
        high = max(high , a);
    }
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        int countLess = 0, countEqual = 0;
        for(auto a : A){
            if(a < mid)
                ++countLess;
            if(a == mid)
                ++countEqual;
        }
        if(countLess < B && countLess + countEqual >= B)
            return mid;
        else if(countLess >= B)
            high = mid - 1;
        else if(countLess < B && countLess + countEqual < B)
            low = mid + 1;
    }
}

// Solution using extra memory
// built in priority_queue, multiset can be used
// nth_element and partial_sort can also be used
int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());

    for(int i = 0; i < B - 1; ++i)
        pq.pop();

    return pq.top();
}
