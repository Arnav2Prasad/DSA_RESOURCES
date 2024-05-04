#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
	int data;
	struct node* right;
	struct node * left;
}node;


struct node * tree_init(int data){
	struct node * nn = (node *)malloc(sizeof(node));
	if (nn){
		nn->data = data;
		nn->right = NULL;
		nn->left = NULL;
	}
	return nn;
}

void tree_insert(node** root , int data){
	struct node * nn = tree_init(data);
	if (*root == NULL){
		*root = nn;
		return;
	}
	// node* p = *root;
	node * curr = *root;
	while (curr != NULL){
		if (curr->data > data){
			// p = curr;
			if (curr->left == NULL){
				curr->left = nn;
				return;
			}
			curr = curr -> left;
		}
		else if (curr->data < data){
			// p = curr;
			if (curr->right == NULL){
				curr->right = nn;
				return;
			}
			curr=curr->right;
		}
		else{
			printf("same value node is there in binary tree!, exiting tree_insert code");
			return;
		}
	}
	// if (p->data > data){
	// 	p->left = nn;
	// }
	// else{
	// 	p->right = nn;
	// }
	return;
}


// -------recursice function-----------------
// Function to insert a node into BST
node* insertNode(node* root, int data) {
    if (root == NULL) {
        return tree_init(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}



void swap(int* a , int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}


node* tree_inorder_succ(node * root){
	printf("in inorder succ function\n");
	node * curr = root->left;
	while (curr!= NULL && curr->right != NULL){
		curr = curr->right;
	}
	printf("inorder_succ function , returning curr : %d\n" , curr->data);
	return curr;
}


node* minValueNode(node* root) {
    node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}



void tree_inorder(node * root){
	if (root==NULL){
		return;
	}
	tree_inorder(root->left);
	printf("%d ",root->data);
	tree_inorder(root->right);
	return;
}


// ITERATIVE FUNCTION
node* tree_delete(node* root, int data) {
    node* current = root;
    node* parent = NULL;
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == NULL) {
        printf("Node not found. Deletion failed.\n");
        return root;
    }
    if (current->left == NULL) {
        if (parent == NULL) {
            root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        free(current);
    } else if (current->right == NULL) {
        if (parent == NULL) {
            root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        free(current);
    } else {
        node* successor = minValueNode(current->right);
        current->data = successor->data;
        current->right = tree_delete(current->right, successor->data);
    }
    return root;
}




// RECURSICE FUNCTION
// Function to delete a node from BST
node* deleteNode(node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int tree_search(node * root , int data){
	if (root == NULL){
		return -1;
	}
	if (root->data > data){
		return tree_search(root->left,data);
	}
	else if (root->data < data){
		return tree_search(root->right , data);
	}
	else{
		return 1;
	}
}

int tree_count(node * root){
	if (root == NULL){
		return 0;
	}
	return 1 + tree_count(root->right) + tree_count(root->left);
}

int max(int a , int b){
	if (a>b){
		return a;
	}
	return b;
}

int tree_height(node * root){
	if (root == NULL){
		return 0;
	}
	return 1 + max(tree_height(root->right) , tree_height(root->left));
}



int main(){
	struct node * root;
	root = NULL;
	// root=tree_init(3);
	// root->left = tree_init(2);
	// root->right = tree_init(5);

	tree_insert(&root,5);
	tree_insert(&root,7);
	tree_insert(&root,1);
	tree_insert(&root,6);
	tree_insert(&root,9);
	tree_insert(&root,0);
	
	printf("tree inorder print : ");		
	tree_inorder(root);
	if (root == NULL){
		printf("root is NULL");
	}
	printf("\n");
	printf("%d\n" , root->data);
	// printf("\n");

	printf("delete operations\n");
	root = tree_delete(root , 5);

	tree_inorder(root);
	printf("\n");

	// node* deleteNode(node* root, int data)
	root = deleteNode(root,1);
	tree_inorder(root);
	printf("\n--------------------\n");



	printf("searching node : ");
	printf("%d\n" , tree_search(root,5));

	printf("Tree height : %d\n" , tree_height(root));
	printf("Tree Count : %d\n" , tree_count(root));

	return 0;
}

	

