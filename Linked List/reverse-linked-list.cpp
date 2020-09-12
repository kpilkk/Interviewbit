// https://www.interviewbit.com/problems/reverse-linked-list/

// using recursion

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if(!A || !A -> next)
        return A;
        
    ListNode* ans = reverseList(A -> next);
    A ->next -> next = A;
    A -> next = NULL;
    
    return ans;
}

// Iterative method

ListNode* Solution::reverseList(ListNode* A) {
    if(!A || !A -> next)
        return A;
        
    ListNode* pre = NULL;
    while(A){
        auto next = A -> next;
        A -> next = pre;
        pre = A;
        A = next;
    }
    
    return pre;
}
