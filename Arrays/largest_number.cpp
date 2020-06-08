// https://www.interviewbit.com/problems/largest-number/

bool compare(string a, string b){
    return a+b > b+a;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> s(A.size());
    for(int i=0;i<A.size();++i){
        s[i] = to_string(A[i]);
    }
    sort(s.begin(), s.end(), compare);
    
    string ans = "";
    int j = 0;
    while(s[j]=="0" && j<A.size()-1){
        ++j;
    }
    // if(j==A.size()) return "0";
    for(int i=j;i<A.size();++i){
        
        ans += s[i];
    }
    return ans;
}
