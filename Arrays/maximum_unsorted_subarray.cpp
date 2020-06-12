// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

// Solution using Extra Memory -- Acceptable on Interviewbit
vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    // if(n==0) 
    vector<int> B(A);
    sort(B.begin(), B.end());
    
    int left = 0, right = 0;
    for(int i=0;i<n;++i){
        if(B[i]!=A[i]){
            left = i;
            break;
        }
    }
    
    for(int i=left;i<n;++i){
        if(B[i]!=A[i]){
            right = i;
        }
    }
    if(left==0 && right==0) return {-1};
    return {left, right};
}

// Interviewbit solution
// Solution without using extra space
vector<int> Solution::subUnsort(vector<int> &A){
	vector<int> ans;
	int n = A.size();
	int i = 0, j = n-1;
	while(i< n - 1 and A[i] <= A[i + 1]){
		i++;
	}
	while(j > 0 and A[j] >= A[j - 1]){
		j--;
	}
    
	if(i == n - 1){ // if array is already sorted, output -1
		ans.push_back(-1);
		return ans;
	}
    
    // following code are for corner cases like 
    // [ 4, 15, 4, 4, 15, 18, 20 ]
    
	int mn = A[i + 1], mx = A[i + 1];
	for(int k = i; k <= j; k++){
		mx = max(mx, A[k]);
		mn = min(mn, A[k]);
	}
	int l = 0, r = n - 1;
	while(A[l] <= mn and l <= i){
	   	l++;
	}
	while(A[r] >= mx and r >= j){
		r--;
	}
	ans.push_back(l);
	ans.push_back(r);
	return ans;
}
