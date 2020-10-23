// https://www.interviewbit.com/problems/merge-k-sorted-lists/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    
    ListNode dummy(0);
    ListNode* ans = &dummy;
    
    while(l1 && l2){
        if(l1 -> val < l2 -> val){
            ans -> next = l1;
            l1 = l1 -> next;
        }
        else{
            ans -> next = l2;
            l2 = l2 -> next;
        }
        ans = ans -> next;
    }
    
    ans -> next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int n = A.size();
    while(n > 1){
        for(int i = 0; i < n / 2; ++i)
            A[i] = mergeTwoLists(A[i], A[n - 1 - i]);
        n = (n + 1) / 2;
    }
    return A.front();
}
