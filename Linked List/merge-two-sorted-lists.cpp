// https://www.interviewbit.com/problems/merge-two-sorted-lists/

// Using recursion

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;

    if(A -> val < B -> val){
        A -> next = mergeTwoLists(A -> next, B);
        return A;
    }
    else{
        B -> next = mergeTwoLists(A, B -> next);
        return B;
    }
}

// Using Extra memory

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(0);
    ListNode* dummy = ans;
    
    while(A && B){
        if(A -> val < B->val){
            ans -> next = new ListNode(A -> val);
            A = A -> next;
        }
        else{
            ans -> next = new ListNode(B -> val);
            B = B -> next;
        }
        ans = ans -> next;
    }
    
    while(A){
        ans -> next = new ListNode(A -> val);
        ans = ans -> next;
        A = A -> next;
    }
    
    while(B){
        ans -> next = new ListNode(B -> val);
        ans = ans -> next;
        B = B -> next;
    }
    
    return dummy -> next;
}
