// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

// 1st solution
// Time Limit Exceeded

int count_bits(int x){
    int ans = 0;
    while(x>0){
        ans += (1&x);
        x >>=1;
    }
    return ans;
}
int Solution::hammingDistance(const vector<int> &A) {
    int mod = 1000000007;
    int ans = 0;
    int n=A.size();
    // if(n==0)
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            ans += count_bits(A[i]^A[j]);
            // cout << ans << " ";
            ans %= mod;
        }
    }
    return (ans*2)%mod;
}

// 2nd solution working



int Solution::hammingDistance(const vector<int> &A) {
    int n = A.size();

    long long ans = 0;
    for(int i=0;i<32;++i){
        int count = 0;
        for(int j=0;j<n;++j)
            if(A[j]&(1<<i)) ++count;

        ans += (2*(long long)count*(n-count));
    }
    return ans%1000000007;
}

