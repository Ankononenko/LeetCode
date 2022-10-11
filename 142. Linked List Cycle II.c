/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    
    if (!head || !head->next) {
        return NULL;
    }
    
    struct ListNode *slow, *fast;
    slow = fast = head;
    
    while(fast && fast->next) {
        
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
        
            struct ListNode *entry = head;
            
            while (slow != entry) {
                slow = slow -> next;
                entry = entry -> next;
            }
            
            return entry;
        }
    }
    return NULL;
}
