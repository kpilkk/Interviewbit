// https://www.interviewbit.com/problems/insertion-sort-list/

ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode dummy(0);
    ListNode *pre = &dummy, *curr = A, *next = nullptr;
    
    while(curr){
        next = curr -> next;
        while(pre -> next && pre -> next -> val < curr -> val)
            pre = pre -> next;
        curr -> next = pre -> next;
        pre -> next = curr;
        pre = &dummy;
        curr = next;
    }
    return dummy.next;
}
