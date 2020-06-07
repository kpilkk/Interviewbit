// https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int left=0, top=0;
    int bottom = A.size()-1;
    int right = A[0].size()-1;
    int dir = 0;
    vector<int> ans;
    
    while(left<=right && top<=bottom){
        if(dir==0){
            for(int i=left;i<=right;++i)
                ans.push_back(A[top][i]);
            top++;
        }
        
        if(dir==1){
            for(int i=top;i<=bottom;++i)
                ans.push_back(A[i][right]);
            right--;
        }
        
        if(dir==2){
            for(int i=right;i>=left;--i)
                ans.push_back(A[bottom][i]);
            bottom--;
        }
        
        if(dir==3){
            for(int i=bottom;i>=top;--i)
                ans.push_back(A[i][left]);
            left++;
        }
        dir = (dir+1)%4;
    }
    // ans.resize(A.size()*A[0].size());
    return ans;
}
