// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(0);
    ListNode* dummy = ans;
    int carry = 0;
    
    while(A || B || carry){
        int x = (A) ? A->val : 0;
        int y = (B) ? B->val : 0;
        
        int sum = x + y + carry;
        carry = sum / 10;
        ans->next = new ListNode(sum % 10);
        ans = ans->next;
        if(A) A = A->next;
        if(B) B = B->next;
    }
    return dummy->next;
}
