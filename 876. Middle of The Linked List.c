// Link to the problem - https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    // Define two pointers to the head of the linked list
    // The first pointer is going to be used to find the total lenght of the linked list
    // The second pointer is going to be used to iterate to the middle of the array 
    // - this is the value that is going to be returned from the function
    struct ListNode* first_pointer = head;
    struct ListNode* second_pointer = head;
    // Total length of the linked list. Is used to find the middle value
    int list_node_length = 0;
    // While the next pointer exist, I move from the head to the end of the array
    // And increment the total length
    while (first_pointer->next) {
        first_pointer = first_pointer->next;
        ++list_node_length;
    }
    // Middle in case if the total legnth is uneven equals to total_lenght / 2 (5 / 2 = 2)
    // In case the total length is even, the middle is total_length / 2 + 1 (6 / 2 + 1 = 4)
    int middle = 0;
    middle = list_node_length % 2 ? list_node_length / 2 + 1: list_node_length / 2;
    // Move the second pointer to the middle value
    for (int index = 0; index < middle; ++index) {
        second_pointer = second_pointer->next;
    }
    
    return second_pointer;
}
