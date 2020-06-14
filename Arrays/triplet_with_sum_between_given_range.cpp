// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

// two pointer solution
int Solution::solve(vector<string> &A) {
    int n = A.size();
    
    if(n<3) return 0;
    sort(A.begin(), A.end());
    
    int l = 0, r = n-1;
    
    while(l<r-1){
        float s = stof(A[l])+stof(A[l+1])+stof(A[r]);
        if(s>=2)
            r = r-1;
        else if(s<1)
            l = l+1;
        else return 1;
    }
    return 0;
}

// Simple solution

int Solution::solve(vector<string> &A) {
    vector<float> temp(A.size());
    
    if(A.size()<3) return 0;

    float a = stof(A[0]);
    float b = stof(A[1]);
    float c = stof(A[2]);

    for(int i=3;i<A.size();++i){
        if(a+b+c>1 && a+b+c<2)
            return 1;

        float temp = stof(A[i]);

        if(a+b+c>=2){
            if(a>b && a>c)
                a = temp;
            else if(b>c && b>a)
                b = temp;
            else
                c = temp;
        }
        else{
            if(a<b && a<c)
                a = temp;
            else if(b<c && b<a)
                b = temp;
            else
                c = temp;
        }
    }

    if(a+b+c>1 && a+b+c<2) return 1;

    return 0;
}
