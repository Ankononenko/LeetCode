// Link to the problem - https://leetcode.com/problems/reverse-linked-list/

void fill_temp_array(int* temp_array, struct ListNode* list, int list_len);
int find_len(struct ListNode* list);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){ 
    // Return NULL if the array is empty
    if (!head) {
        return NULL;
    }
    // Find the length of the incomming list to create a temporary list with a certain size
    int head_len = 0;
    // Call a function to find the lenght
    head_len = find_len(head);
    // Create a temp array for the flip
    int temp_array[head_len];
    // Fill the temp array with default values of zeros
    memset(temp_array, 0, head_len * sizeof(int));
    // Fill the temp array with linked list values
    fill_temp_array(temp_array, head, head_len);
    // Overwrite the linked array with the flipped values to save memory
    // Current is used to keep head of the array intact - it's going to be returned from the function
    struct ListNode* current = head;
    for (int i = head_len - 1; i >= 0; --i) {
        current->val = temp_array[i];
        current = current->next;
    }
    return head;
}
// Function to fill temp array with the values of linked list
void fill_temp_array(int* temp_array, struct ListNode* list, int list_len) {
    for (int i = 0; i < list_len; ++i) {
        temp_array[i] = list->val;
        list = list->next;
    }
}
// Function to find the lenght of the linked array
int find_len(struct ListNode* list) {
    int len = 0;
    while (list) {
        list = list->next;
        ++len;
    }
    return len;
}
