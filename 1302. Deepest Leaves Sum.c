/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct Queue {
    struct TreeNode **arr;
    int front, rear, capacity;
};

struct Queue *createQueue(int capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->arr = (struct TreeNode **)malloc(capacity * sizeof(struct TreeNode *));
    queue->front = queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(struct Queue *queue, struct TreeNode *node) {
    queue->arr[queue->rear] = node;
    queue->rear = (queue->rear + 1) % queue->capacity;
}

struct TreeNode *dequeue(struct Queue *queue) {
    struct TreeNode *node = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return node;
}

int isQueueEmpty(struct Queue *queue) {
    return queue->front == queue->rear;
}

int deepestLeavesSum(struct TreeNode *root) {
    if (!root) return 0;

    struct Queue *queue = createQueue(10000);
    int level_sum = 0;
    enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        int level_size = (queue->rear - queue->front + queue->capacity) % queue->capacity;
        level_sum = 0;

        for (int i = 0; i < level_size; i++) {
            struct TreeNode *node = dequeue(queue);
            level_sum += node->val;

            if (node->left) enqueue(queue, node->left);
            if (node->right) enqueue(queue, node->right);
        }
    }

    free(queue->arr);
    free(queue);
    return level_sum;
}
