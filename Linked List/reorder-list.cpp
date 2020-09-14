// https://www.interviewbit.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A -> next)
        return A;
        
    // First to find the mid element
    ListNode *mid = A, *temp = A -> next;
    while(temp && temp -> next){
        mid = mid -> next;
        temp = temp -> next -> next;
    }
    
    temp = mid -> next;
    // Reverse the second half
    while(temp -> next){
        ListNode* t = mid -> next;
        mid -> next = temp -> next;
        temp -> next = mid -> next -> next;
        mid -> next -> next = t;
    }
    
    // Rearrange the array
    temp = A;
    while(temp != mid){
        ListNode* t = temp -> next;
        temp -> next = mid -> next;
        mid -> next = temp -> next -> next;
        temp -> next -> next = t;
        temp = t;
    }
    return A;
}
