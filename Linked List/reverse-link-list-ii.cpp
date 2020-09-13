// https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A == NULL)
        return A;
        
    ListNode *curr = A, *prev = NULL;
    
    while(B > 1){
        prev = curr;
        curr = curr -> next;
        B--;
        C--;
    }
    
    ListNode *pre = prev, *tail = curr;
    ListNode* next = NULL;
    
    while(C--){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    if(pre)
        pre -> next = prev;
    else
        A = prev;
        
    tail -> next = curr;
    
    return A;
}
