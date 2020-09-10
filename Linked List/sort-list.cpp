// https://www.interviewbit.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* mergeSort(ListNode* left, ListNode* right){
    if(left == NULL)
        return right;
        
    if(right == NULL)
        return left;
        
    if(left -> val < right -> val){
        left -> next = mergeSort(left -> next, right);
        return left;
    }
    else{
        right -> next = mergeSort(left, right -> next);
        return right;
    }
}

ListNode* Solution::sortList(ListNode* A) {
    if(A == NULL || A -> next == NULL)
        return A;
        
    ListNode *pre = NULL, *slow = A, *fast = A;
    while(fast && fast -> next){
        pre = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    pre -> next = NULL;
    
    return mergeSort(sortList(A), sortList(slow));
}
