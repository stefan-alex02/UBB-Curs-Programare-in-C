/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *A = NULL, *B = head, *C;
    if(B != NULL)
    {
        C = B->next;
        while(C != NULL)
        {
            B->next = A;
            A = B;
            B = C;
            C = C->next;
        }
        B->next = A;
        return B;
    }
    else
        return head;
}