/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;
struct ListNode* middleNode(struct ListNode* head) {
    node* fast = head;
    node* slow = head;
    while(fast->next != NULL){
        if(fast->next->next == NULL) // if node count is even
            return slow->next;
        else{
        fast=fast->next->next;
        slow = slow->next;
        }
    }
    return slow; // if node count is odd,this will return.
}
