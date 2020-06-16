// https://www.interviewbit.com/problems/prettyprint/

vector<vector<int> > Solution::prettyPrint(int A) {
    int dim = 2*A-1;
    vector<vector<int>> res(dim, vector<int>(dim));
    if(A==1){
        res[0][0] =1;
        return res;
    }
    
    int left=0, right=dim-1, top=0, bottom=dim-1;

    while(left<=right&&top<=bottom){
        for(int i=left;i<=right;++i){
            res[top][i] = A;
        }
        ++top;
        
        for(int i=top;i<=bottom;++i){
            res[i][right] = A;
        }
        --right;
        
        for(int i=right;i>=left;--i){
            res[bottom][i] = A;
        }
        --bottom;
        
        for(int i=bottom;i>=top;--i){
            res[i][left] = A;
        }
        ++left;
        
        A--;
    }
    return res;
}
