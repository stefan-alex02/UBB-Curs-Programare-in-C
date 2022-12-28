/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *A = NULL, *B = head, *C, *st_ls, *st_rev, *dr_ls, *dr_rev;
    if(B != NULL)
    {
        int i;
        C = B->next;
        for(i = 1; i < left; i++)
        {
            A = B;
            B = C;
            C = C->next;
        }
        st_ls = A;
        st_rev = B;

        for(; i < right; i++)
        {
            B->next = A;
            A = B;
            B = C;
            C = C->next;
        }

        dr_rev = B;
        dr_ls = B->next;
        
        B->next = A;

        if(st_ls == NULL)
            head = dr_rev;
        else
            st_ls->next = dr_rev;
        st_rev->next = dr_ls;

        return head;
    }
    else
        return head;
}