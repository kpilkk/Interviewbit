// https://www.interviewbit.com/problems/roman-to-integer/

int Solution::romanToInt(string A) {
    int ans = 0, n = A.size();
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    int temp = roman[A[n - 1]];
    ans += temp;
    
    for(int i = n - 1; i > 0; --i){
        int temp1 = roman[A[i - 1]];
        if(temp <= temp1){
            temp = temp1;
            ans += temp1;
        }
        else{
            ans -= temp1;
        }
    }
    return ans;
}
