// https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    if(n < 4) return {};
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    
    for(int i = 0; i < n - 3; ++i){
        if(i && A[i] == A[i - 1])
            continue;
        if(A[i] + A[i + 1] + A[i + 2] + A[i + 3] > B)
            break;
        if(A[i] + A[n - 3] + A[n - 2] + A[n - 1] < B)
            continue;    
        for(int j = i + 1; j < n - 2; ++j){
            if(j > i + 1 && A[j] == A[j - 1])
                continue;
            if(A[i] + A[j] + A[j + 1] + A[j + 2] > B)
                break;
            if(A[i] + A[j] + A[n - 2] + A[n - 1] < B)
                continue; 
            int l = j + 1;
            int r = n - 1;
            while(l < r){
                int sum = A[i] + A[j] + A[l] + A[r];
                if(sum > B)
                    --r;
                else if(sum < B)
                    ++l;
                else{
                    ans.push_back({A[i], A[j], A[l], A[r]});
                    do{
                        ++l;
                    } while(l < r && A[l] == A[l - 1]);
                    do{
                        --r;
                    } while(l < r && A[r] == A[r + 1]);
                }
            }
        }
    }
    return ans;
}
