void search(struct Node* root, int* return_array, int* i_return_array);

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* preorder(struct Node* root, int* returnSize) {
    
    int* return_array = (int*) malloc(10000 * sizeof(int));
    int i_return_array = 0;
    
    search(root, return_array, &i_return_array);
    
    *returnSize = i_return_array;
    
    return return_array;
}

void search(struct Node* root, int* return_array, int* i_return_array) {
    
    if (!root) {
        return;
    }
    
    return_array[(*i_return_array)++] = root->val;
    
    for (int i = 0; i < root->numChildren; ++i) {
        search(root->children[i], return_array, i_return_array);
    }
}
