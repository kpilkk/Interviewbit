// https://www.interviewbit.com/problems/prime-sum/

// 1st solution

bool Isprime(int x){
    int lim = sqrt(x);
    for(int i=2;i<=lim;++i){
        if(x%i == 0) return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> ans;
    for(int i=2;i<=A/2;++i){
        if(Isprime(i) && Isprime(A-i)){
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
}

// 2nd solution
// using Sieve of Eratosthenes

vector<int> Solution::primesum(int A) {
    vector<bool> prime(A+1, true);
    prime[0] = prime[1] = false;
    
    for(int i=2;i<A;++i){
        if(prime[i]){
            for(int j=2*i;j<A;j+=i){
                prime[j] = false;
            }
        }
    }
    
    vector<int> ans;
    for(int i=2;i<=A/2;++i){
        if(prime[i] && prime[A-i]){
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
}
