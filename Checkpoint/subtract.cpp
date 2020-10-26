// https://www.interviewbit.com/problems/subtract/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Reverse first half, then subtract by maintaining two pointers one after the middle and the other at head
// then subtract till mid and then reverse first half
ListNode* Solution::subtract(ListNode* A) {
    if(!A || !A -> next)
        return A;
    
    ListNode* temp = A;
    int n = 0;
    while(temp){
        temp = temp -> next;
        ++n;
    }
    
    int half = n / 2;

    ListNode *curr = A, *prev = nullptr, *nxt = nullptr;
    while(half--){
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    A -> next = nxt;
    
    
    if(n % 2 == 0)
        half = n / 2;
    else
        half = n / 2 + 1;
    
    curr = prev, temp = prev;
    while(half--)
        curr = curr -> next;
    

    while(curr){
        temp -> val = curr -> val - temp -> val;
        temp = temp -> next;
        curr = curr -> next;
    }
    
    half = n / 2;
    ListNode* pre = nullptr;
    curr = prev, nxt = nullptr;
    while(half--){
        nxt = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = nxt;
    }
    prev -> next = nxt;
    
    return pre;
}
