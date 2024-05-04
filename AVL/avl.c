/*
    * ---------------------------------------------------------------------------  
    *                           AVL
    * WHAT IS BST?
    *   BST stands for Binary Search Tree
    *   in it left child < root < right child
    *               40
    *             /    \ 
    *           20      50
    *          /  \    /   \
    *        10   30  45    60
    * 
    *   it is useful for efficient searching --> o(height) 
    * 
    *   DRAWBACKS OF BST
    * For same elements, but different order , we get BST of different height
    * On given array(series of order of input elements) we get different BST
    * We get BST of difference height
    * Total possibilities of BST :   2n
    *                                  C
    *                                    n-1
    * 
    * Example:
    *  for order of elements : 30,10,20      AND   20,10,30
    *       30                                      20
    *      /                                      /    \
    *     10                                    10      30
    *       \
    *        20 
    *   height = 3                                height=2
    * 
    * So for skewed tree : insertion and searching complexity may be : O(n)
    *   O(ln n) <= insert and serach <= o(n)   --> it depends on order of input of elements 
    * 
    * HOW TO IMPROVE?
    *   We can construct a height balanced BST 
    *   so that insert, search complexity would be O(ln n)
    * 
    *  It uses the concept of balance factor 
    *   Balance Factor  =   height of   -    height of
    *                      left subtree    right subtree
    *   if | bf | > 1 : tree is imbalanced
    *   if | bf | <= 1 : tree is balanced
    * 
    * In order to get tree as balanced : we introduce the concept of "ROTATIONS!"
    *  Rotation includes : LL,RR,LR,RL rotation
    * Rotation is performed on 3 nodes only!
    * 
    * INSERTION : 
    * While inserting elements in the AVL tree , as soon as a node becomes imbalance,
    * perform rotation , Dont wait for other keys to get inserted and then perform rotation.
    * 
    * If multiple nodes are imbalanced , start performing rotation with the "lower" one
    * No 2 nodes can have the same value.
    *  
    * Time Complexity : O(ln n)
    * 
    * 
    * SEARCHING:
    * To search key 'K' in the AVL tree:
    *  if  root > k:
    *              go to left subtree 
    *  if root < k:
    *               go to right subtree
    *  if root == k:
    *               node found !
    * 
    * Time Complexity : O(ln n)
    * 
    * 
    * DELETION:
    * To delete key 'k' in the AVL tree:
    * 
    * Find the node to be deleted :
    *  CASE 1 : if the node has no child  --> delete it
    *  CASE 2 : if the node has only 1 children --> replace the node with 
    *           the children and delete the node
    * CASE 3 : if the node has 2 children --> you have 2 options
    *           one is to replace the node with the largest value node
    *               of its left subtree and then delete the node.
    *           other option is to replace the node with the smallest value node
    *               of its right subtree and then delete the node.
    * 
    * Time Complexity : O(ln n)
    * 
    * After deletion of the node , check if the tree has becomed imbalanced or not
    * If imbalanced : perfoarm suitable rotations(LL,RR,LR,RL)
    * 
    *    HEIGHT : 
    *  int height(root);
    *   if (root == NULL){
    *       return 0;
    *   }               ---> height of leaves is 0
    *           
    *           
    *               50
    *             /    \
    *            20    70
    *           / \
    *          10  30
    * 
    *   height of a node 'n' is maximum of height of the right subtree and left subtree
    *    height of leaf node is 0
    * 
    * Time Complexity : O(n)
    * 
    * NOTE : Duplicates are not allowed in AVL tree
    *
    * 
    * We choose AVL due its properties of fast searching,inserting and deleting:)
    * 
    * We used AVL in : 1. db_desc_verb_tree  
    *                  2. db_verb_tree 
    *                  3. verb_tree
    *                  4. noun_tree
    * ------------------------------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
	int data;
	struct avl* left;
	struct avl* right;
	int bf;
}avl;

avl* init(int data){
	avl* nn = (avl *)malloc(sizeof(avl));
	if (nn){
		nn->data = data;
		nn->right = NULL;
		nn->left = NULL;
		nn->bf = 1;
	}
	return nn;
}

int max(int a, int b){
	if (a>b){
		return a;
	}
	return b;
}

int height(avl* root){
	if (root == NULL){
		return 0;
	}
	return max(height(root->left),height(root->right)) + 1;
}

void balance(avl* root){
	int lh = height(root->left);
	int rh = height(root->right);

	root->bf = lh-rh;
	return;
}	

avl* LL(avl* root,avl* p){
	avl* pl = p->left;
	avl* plr = pl->right;

	//p->left-pl->right;
	pl->right=p;
	p->left = plr;

	balance(p);
	balance(pl);
	
	if (root==p){
		root=pl;
	}
	return pl;
}

avl* RR(avl* root,avl* p){
	avl* pr = p->right;
	avl* prl = pr->left;

	pr->left = p;
	p->right = prl;

	balance(p);
	balance(pr);

	if (root==p){
		root = pr;
	}
	return pr;
}

avl* LR(avl* root,avl* p){
	avl* pl=p->left;
	avl* plr = pl->right;

	pl->right = plr->left;
	p->left = plr->right;

	plr->left = pl;
	plr->right = p;

	balance(p);
	balance(pl);
	balance(plr);

	if (root==p){
		root=plr;
	}
	return plr;
}

avl *RL(avl* root,avl* p){
	avl* pr=p->right;
	avl* prl = pr->left;

	p->right = prl->left;
	pr->left = prl->right;

	prl->right = pr;
	prl->left = p;

	balance(p);
	balance(pr);
	balance(prl);

	if (root==p){
		root=prl;
	}
	return prl;
}


avl* insert(avl* root,avl* p,int data){
	if (p==NULL){
		avl* nn = init(data);
		return nn;
	}

	if (p->data > data ){
		p->left = insert(root,p->left,data);
	}
	else if (p->data < data ){
		p->right = insert(root,p->right,data );
	}
	
	balance(p);
	
	
	if (p->bf == 2){
		if (p->left->bf == -1){
			return LR(root,p);
		}
		else{
			return LL(root,p);
		}
	}
	else if (p->bf == -2){
		if (p->right->bf == 1){
			return RL(root,p);
		}
		else{
			return RR(root,p);
		}
	}
	

	return p;


	//balance(p);
}

void inorder(avl* root){
	if (root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data );
	inorder(root->right);
	return;
}

avl* in_pre(avl* root){
	while (root && root->right != NULL){
		root = root->right;
	}
	return root;
}

avl* in_succ(avl* root){
	while (root && root->left!=NULL){
		root = root->left;
	}
	return root;
}

avl* delete_avl(avl* root,avl* p,int data){
	if (p==NULL){
		return NULL;
	}
	if (p->left == NULL && p->right == NULL){
		if (p==root){
			root=NULL;
		}
		free(p);
		return NULL;
	}
    

	if (data < p->data ){
		p->left = delete_avl(root,p->left,data);
	} else if(p->data < data ){
		p->right = delete_avl(root,p->right,data);
	}else{
		
		avl* q;
		if (height(p->left) > height(p->right)){
			q = in_pre(p->left);
			p->data = q->data ;
			p->left = delete_avl(root,p->left,q->data);
		} else{
			q=in_succ(p->right);
			p->data = q->data;
			p->right=delete_avl(root,p->right,q->data);
		}
		
	}
	balance(p);

		
	if (p->bf == 2){
		if (p->left->bf == -1){
			return LR(root,p);
		}
		else{
			return LL(root,p);
		}
	}
	else if (p->bf == -2){
		if (p->right->bf == 1){
			return RL(root,p);
		}
		else{
			return RR(root,p);
		}
	}

	return p;
}
	

int main(){
	avl* root = NULL;

	// root = insert(root,root,10);
	// root = insert(root,root,20);
	// root = insert(root,root,5);
	// root=insert(root,root,30);
	// root = insert(root,root,40);

    root = insert(root,root,10);
    root = insert(root,root,20);
    root = insert(root,root,30);
    root = insert(root,root,40);
    root = insert(root,root,50);

	inorder(root);

	printf("\n");

	root = delete_avl(root,root,20);
	inorder(root);
	printf("\n");

	return 0;
}