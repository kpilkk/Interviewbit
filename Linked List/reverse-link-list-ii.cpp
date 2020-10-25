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

// Most elegant solution using linked list 1
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B != 1){
        A -> next = reverseBetween(A -> next, B - 1, C - 1);
        return A;
    }
    else{
        ListNode *prev = nullptr,*temp = A, *next = nullptr;
        int count = 0;
        while(count++ < C){
            next = A -> next;
            A -> next = prev;
            prev = A;
            A = next;
        }
        temp -> next = A;
        return prev;
    }
}
