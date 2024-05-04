#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;



// Structure for stack
typedef struct {
    int top;
    int capacity;
    TreeNode **array;
} Stack;


// Function to create a new stack
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (TreeNode **)malloc(capacity * sizeof(TreeNode *));
    if (stack->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return stack;
}

// Check if stack is full
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push element onto stack
void push(Stack *stack, TreeNode *node) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->array[++(stack->top)] = node;
}

// Pop element from stack
TreeNode *pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->array[(stack->top)--];
}

// Function to perform iterative inorder traversal
void inorderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    Stack *stack = createStack(100); // Adjust capacity as needed
    TreeNode *current = root;
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->val);
        current = current->right;
    }
    free(stack->array);
    free(stack);
}

// Function to perform iterative preorder traversal
void preorderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    Stack *stack = createStack(100); // Adjust capacity as needed
    push(stack, root);
    while (!isEmpty(stack)) {
        TreeNode *node = pop(stack);
        printf("%d ", node->val);
        if (node->right != NULL) {
            push(stack, node->right);
        }
        if (node->left != NULL) {
            push(stack, node->left);
        }
    }
    free(stack->array);
    free(stack);
}

// Function to perform iterative postorder traversal
void postorderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    Stack *stack1 = createStack(100); // Stack for storing nodes
    Stack *stack2 = createStack(100); // Stack for storing postorder traversal
    push(stack1, root);
    while (!isEmpty(stack1)) {
        TreeNode *node = pop(stack1);
        push(stack2, node);
        if (node->left != NULL) {
            push(stack1, node->left);
        }
        if (node->right != NULL) {
            push(stack1, node->right);
        }
    }
    while (!isEmpty(stack2)) {
        TreeNode *node = pop(stack2);
        printf("%d ", node->val);
    }
    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);
}

// Function to create a new node
TreeNode *createNode(int val) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create a sample binary tree
    TreeNode *root = createNode(5);
    root->left = createNode(1);
    root->right = createNode(7);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    // Print inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Print preorder traversal
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Print postorder traversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
