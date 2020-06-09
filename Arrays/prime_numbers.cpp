// https://www.interviewbit.com/problems/prime-numbers/

vector<int> Solution::sieve(int A) {
    // Sieve of Eraosthenes
    // int n = A.size();
    vector<bool> prime(A+1, true);
    prime[0] = false;
    prime[1] = false;
    
    for(int i=2;i<=A;++i){
        if(prime[i]){
            for(int j=2*i;j<=A;j+=i)
                prime[j] = false;
        }
    }
    vector<int> ans;
    for(int i=2;i<=A;++i){
        if(prime[i]) ans.push_back(i);
    }
    return ans;
}
