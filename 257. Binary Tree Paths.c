void dfs(struct TreeNode* node, char **strArray, int *strIndex, int length, char *buffer){
    length += sprintf(buffer+length, "%d", node->val);
    if(!node->left && !node->right){
        *(strArray+*strIndex) = malloc(600*sizeof(char));
        strcpy(*(strArray+*strIndex), buffer);
        (*strIndex)++;
    } else {
        length += sprintf(buffer+length, "->");
        if(node->left){
            dfs(node->left, strArray, strIndex, length, buffer);
        }
        if(node->right){
            dfs(node->right, strArray, strIndex, length, buffer);
        }
    }
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char **ans = malloc(50*sizeof(char *));
    int strIndex = 0;
    char buffer[600];
    dfs(root, ans, &strIndex, 0, buffer);
    *returnSize = strIndex;
    return ans;
}
