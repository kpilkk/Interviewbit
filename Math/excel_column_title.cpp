// https://www.interviewbit.com/problems/excel-column-title/

// My working solution

string Solution::convertToTitle(int A) {
    string ans ="";

    while(A){
        if(A%26==0){
            ans += 'Z';
            A = A/26 - 1;
        }
        else{
            ans += ((A%26)+'A'-1);
            A /= 26;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// More efficient solution given by Interviewbit

string Solution::convertToTitle(int A) {
    string ans ="";
    
    while(A){
        ans = (char)((A-1)%26 + 'A') + ans;
        A = (A-1)/26;
    }
    return ans;
}
