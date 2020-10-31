* [Regular Expression II](https://www.interviewbit.com/problems/regular-expression-ii/)
  [Recursive and Easy DP solution](https://leetcode.com/problems/regular-expression-matching/discuss/5665/My-concise-recursive-and-DP-solutions-with-full-explanation-in-C%2B%2B)
   * [Concise solution with space optimization](https://leetcode.com/problems/regular-expression-matching/discuss/5684/C%2B%2B-O(n)-space-DP)
      * Solution can be optimized to use O(n) space.
* [Regular Expression Match](https://www.interviewbit.com/problems/regular-expression-match/)
  [DP solution](https://leetcode.com/problems/wildcard-matching/discuss/370736/Detailed-Intuition-From-Brute-force-to-Bottom-up-DP)
    * It can be solved in [linear time](https://www.geeksforgeeks.org/dynamic-programming-wildcard-pattern-matching-linear-time-constant-space/).
* [Longest valid Parentheses](https://www.interviewbit.com/problems/longest-valid-parentheses/)
  [Explanation](https://leetcode.com/problems/longest-valid-parentheses/solution/)
  * Algorithm without using extra space
    * In this approach, we make use of two counters `left` and `right`. First, we start traversing the string from the left towards the right and for every `(` encountered, we increment the left counter and for every `)` encountered, we increment the right counter. Whenever left becomes equal to right, we calculate the length of the current valid string and keep track of maximum length substring found so far. If right becomes greater than left we reset left and right to 0.

    * Next, we start traversing the string from right to left and similar procedure is applied.
