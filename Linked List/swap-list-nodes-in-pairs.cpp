// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

// Iterative solution using constant space
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A) return A;
    
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = A;
    
    while(A && A -> next){
        ListNode* temp = A -> next;
        A -> next = temp -> next;
        temp -> next = A;
        pre -> next = temp;
        pre = A;
        A = A -> next;
    }
    return dummy.next;
}
