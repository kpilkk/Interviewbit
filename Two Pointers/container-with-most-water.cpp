// https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &A) {
    int i = 0, j = A.size() - 1;
    int max_water = 0;
    while(i < j){
        max_water = max(max_water, (j - i) * min(A[j], A[i]));
        if(A[i] < A[j])
            ++i;
        else
            --j;
    }
    return max_water;
}
