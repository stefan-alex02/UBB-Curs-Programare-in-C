/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carrier = 0;
    struct ListNode* result = NULL;
    struct ListNode* result_iter;
    while(l1 != NULL || l2 != NULL)
    {
        int val1 = 0, val2 = 0;
        if(l1 != NULL)
        {
            val1 = l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            val2 = l2->val;
            l2 = l2->next;
        }
        
        if(result != NULL)
        {
            result_iter->next = malloc(sizeof(struct ListNode));
            result_iter = result_iter->next;
        }
        else
        {
            result = malloc(sizeof(struct ListNode));
            result_iter = result;
        }
        
        result_iter->val = (val1 + val2 + carrier) % 10;
        carrier = (val1 + val2 + carrier) / 10;
    }
    if(carrier == 1)
    {
        result_iter->next = malloc(sizeof(struct ListNode));
        result_iter = result_iter->next;

        result_iter->val = carrier;
    }
    result_iter->next = NULL;
    return result;
}
