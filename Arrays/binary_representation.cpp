// https://www.interviewbit.com/problems/binary-representation/

string Solution::findDigitsInBinary(int A) {
    if(A==0) return "0";
    // if(A==1) return "1";
    string ans = "";
    while(A>=1){
        ans = to_string(A%2) + ans;
        A /= 2;
    }
    return ans;
}
