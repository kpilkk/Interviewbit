// https://www.interviewbit.com/problems/list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A) return NULL;
    bool cycle = false;
    ListNode *slow = A, *fast = A;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            cycle = true;
            break;
        }
    }
    if(!cycle) return NULL;
    slow = A;
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
