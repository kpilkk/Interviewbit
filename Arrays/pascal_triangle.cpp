// https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    if(A==0) return {};
    
    vector<vector<int>> ans;
    
    ans.push_back({1});
    if(A==1) return ans;
    ans.push_back({1,1});
    if(A==2) return ans;
    
    for(int i=2;i<A;++i){
        vector<int> temp(i+1);
        temp[0] = temp[i] = 1;
        for(int j=1;j<i;++j){
            temp[j] = ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(temp);
    }
    return ans;
}
