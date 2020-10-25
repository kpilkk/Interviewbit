// https://www.interviewbit.com/problems/k-reverse-linked-list/

// Using Reverse Linked List I and Reverse Linked List II
/*
 * Following code is similar to Reverse Linked List II
*/
ListNode* reverseBetween(ListNode* head, int m, int n){
    if(m != 1){
        head -> next = reverseBetween(head -> next, m - 1, n - 1);
        return head;
    }
    else{
        /*
         * Following code is similar to Reverse Linked List I
        */
        ListNode *prev = nullptr, *temp = head, *next = nullptr;
        int count = 0;
        while(count++ < n){
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        temp -> next = head;
        return prev;
    }
}
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B == 0 || B == 1)
        return A;
    
    int n = 0, i = 1;
    ListNode *temp = A;
    while(temp){
        temp = temp -> next;
        ++n;
    }
    
    while(i + B <= n + 1){
        A = reverseBetween(A , i , i + B - 1);
        i += B;
    }
    
    return A;
}
