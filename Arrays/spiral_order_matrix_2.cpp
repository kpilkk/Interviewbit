// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans(A, vector<int>(A));
    
    int left=0, right=A-1, top=0, bottom=A-1;
    
    int dir = 0;
    int k = 1;
    while(left<=right && top<=bottom){
        if(dir==0){
            for(int i=left;i<=right;++i){
                ans[top][i] = k++;
            }
            top++;
        }
        else if(dir==1){
            for(int i=top;i<=bottom;++i){
                ans[i][right] = k++;
            }
            right--;
        }
        else if(dir==2){
            for(int i=right;i>=left;--i){
                ans[bottom][i] = k++;
            }
            bottom--;
        }
        else if(dir==3){
            for(int i=bottom;i>=top;--i){
                ans[i][left] = k++;
            }
            left++;
        }
        dir = (dir+1)%4;
    }
    return ans;
}
