// https://www.interviewbit.com/problems/single-number-ii/

// Simple solution
int Solution::singleNumber(const vector<int> &A) {
	// First time number appear -> save it in "ones"
 
	// Second time -> clear "ones" but save it in "twos" for later check
	
	// Third time -> try to save in "ones" but value saved in "twos" clear it
	int ones=0, twos=0;
	for(int i=0;i<A.size();++i){
		ones = (ones^A[i]) & ~twos;
		twos = (twos^A[i]) & ~ones;
	}
	return ones;
}

//Explanation
/*The code seems tricky and hard to understand at first glance.
However, if you consider the problem in Boolean algebra form, everything becomes clear.

What we need to do is to store the number of '1's of every bit. Since each of the 32 bits follow the same rules, we just need to consider 1 bit. We know a number appears 3 times at most, so we need 2 bits to store that. Now we have 4 state, 00, 01, 10 and 11, but we only need 3 of them.

In this solution, 00, 01 and 10 are chosen. Let 'ones' represents the first bit, 'twos' represents the second bit. Then we need to set rules for 'ones' and 'twos' so that they act as we hopes. The complete loop is 00->10->01->00(0->1->2->3/0).

    1.For 'ones', we can get 'ones = ones ^ A[i]; if (twos == 1) then ones = 0', that can be tansformed to 'ones = (ones ^ A[i]) & ~twos'.

    2.Similarly, for 'twos', we can get 'twos = twos ^ A[i]; if (ones* == 1) then twos = 0' and 'twos = (twos ^ A[i]) & ~ones'. Notice that 'ones*' is the value of 'ones' after calculation, that is why twos is
    calculated later.*/
	
// Interviewbit Approach 1
class Solution {
public:
    int singleNumber(const vector<int> &A) {
            int n = A.size();
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
};

// Explanation
/*

Let us look at every bit position.

Every number that occurs thrice will either contribute 3 ‘1’s or 3 ‘0’s to the position.

The number that occurs once X will contribute exactly one 0 or 1 to the position depending on whether it has 0 or 1 in that position.

So:

   1. If X has 1 in that position, we will have (3x+1) number of 1s in that position.
   2. If X has 0 in that position, we will have (3x+1) number of 0s in that position.

Can you think of a solution using the above observation?
*/

/*Having noticed that if X has 1 in that position, we will have 3x+1 number of 1s in that position. If X has 0 in that position, we will have 3x+1 number of 0 in that position.

A straightforward implementation is to use an array of size 32 to keep track of the total count of ith bit.

We can improve this based on the previous solution using three bitmask variables:

ones as a bitmask to represent the ith bit had appeared once.
twos as a bitmask to represent the ith bit had appeared twice.
threes as a bitmask to represent the ith bit had appeared three times.
When the ith bit had appeared for the third time, clear the ith bit of both ones and twos to 0. The final answer will be the value of ones*/

// Interviewbit Approach 2

class Solution {
public:
int singleNumber(const vector<int> &A) {
		int n = A.size();
		int ones = 0, twos = 0, threes = 0;
		for (int i = 0; i < n; i++) {
			twos |= ones & A[i];
			ones ^= A[i];
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
}
