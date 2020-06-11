// https://www.interviewbit.com/problems/add-one-to-number/

// Working solution
vector<int> Solution::plusOne(vector<int> &A) {
    reverse(A.begin(), A.end());
    
    int carry = 0; // to take care of corner case
    for(int i=0;i<A.size();++i){
        if(A[i]!=9){
            A[i] = A[i]+1;
            carry = 0;
            break;
        }
        else{
            A[i] = 0;
            carry = 1;
        }
    }
    
    if(carry == 1) A.push_back(1);
    
    int i = A.size()-1;
    
    while(A[i]==0){
        A.pop_back();
        --i;
    }
    
    reverse(A.begin(), A.end());
    return A;
}
