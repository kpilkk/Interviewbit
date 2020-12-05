* [Kth Smallest Element In The Array](https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/)
  [Explanation 1](https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort)
  [Explanation 2](https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained)
  [Explanation without using Extra variable](https://www.geeksforgeeks.org/kth-smallest-element-in-the-array-using-constant-space-when-array-cant-be-modified/)
* [NUMRANGE](https://www.interviewbit.com/problems/numrange/)
  [Explanation](https://www.geeksforgeeks.org/number-of-subarrays-having-sum-in-a-given-range/)
    * If negative numbers are included in the problem statement, then mentioned solution will not work.
    * For better problem statemnt and its explanation, one can solve [Leetcode](https://leetcode.com/problems/count-of-range-sum/) question.
    * It can also be solved similar to [Counting Subarrays!](https://www.interviewbit.com/problems/counting-subarrays/) by combining two problems.
* [SUBTRACT](https://www.interviewbit.com/problems/subtract/)
    * It can be solved by reversing first half and subtracting by maintaining two pointers and again reversing first half.
* [NEXTGREATER](https://www.interviewbit.com/problems/nextgreater/)
    * It can be solved using stack.
* [Longest Consecutive Sequence](https://www.interviewbit.com/problems/longest-consecutive-sequence/)
    * Although Interviewbit does accept some solutions, which doesn't satisfy all test cases. Like,<br>
    ```2 2147483647 -2147483648 or 2 -2147483647 -2147483648```
    * i.e. if one of the digit is maximum of integer or minimum of integer.
* [Valid Binary Search Tree](https://www.interviewbit.com/problems/valid-binary-search-tree/)
  * Recursive solution mentioned in this will not pass all test cases in other platforms such as LeetCode for input with root as 0 and the only right child as -1.
  * [Better Explanation](https://leetcode.com/problems/validate-binary-search-tree/discuss/959657/C%2B%2B-recursive-solution-passing-all-test-cases)
  * Must [read](https://leetcode.com/problems/validate-binary-search-tree/discuss/32112/Learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-(Java-Solution)) to solve various problems on Trees.
