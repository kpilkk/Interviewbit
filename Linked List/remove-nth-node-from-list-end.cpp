// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = A;
    ListNode* first = A;
    int length = 0;
    
    while(first){
        first = first -> next;
        length++;
    }
    
    if(B > length)
        length = 0;
    else
        length -= B;
        
    first = dummy;
    
    while(length--){
        first = first -> next;
    }
    
    ListNode * tmp = first -> next;
    first -> next = first -> next -> next;
    if(tmp)
        delete tmp;
        
    return dummy -> next;
}
