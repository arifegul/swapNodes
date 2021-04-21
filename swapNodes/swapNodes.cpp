#include <stdio.h>
#include <stdlib.h>  

//Binary tree has data,pointer left&right child
struct binaryTreeNode{  
    int data;  
    struct binaryTreeNode *left;  
    struct binaryTreeNode *right;  
};



//I created a new node  
struct binaryTreeNode *createNodes(int data){  
    //I created new node  
    struct binaryTreeNode *node = (struct binaryTreeNode*)malloc(sizeof(struct binaryTreeNode));  
    // Assign data to newNode, leftchildren= NULL and rightchildren=NULL  
    node -> data = data;  
    node -> left = NULL;  
    node -> right = NULL;  
      
    return node;  
}  

 struct binaryTreeNode *generateBinaryTree(){
    //I define root&nodes
    struct binaryTreeNode *root = createNodes(5);
    root->left = createNodes(7);
    root->right = createNodes(9);
    root->left->left = createNodes(11);
    root->left->right = createNodes(13);
    root->right->left = createNodes(15);
    root->right->right = createNodes(17);
    root->left->left->left = createNodes(19);
    root->right->left->left = createNodes(21);
    root->right->left->right = createNodes(23);
    root->right->left->left->left = createNodes(25);
    
    return root;
 
}

//I wrote the previous Inorder function before without swap
void findInorder(struct binaryTreeNode *node) {
	
	if (node == NULL)
    	return;
          
    findInorder(node->left);
     
    printf("%d ", node->data); 
     
    findInorder(node->right);
}

// Here, I have defined a temporary temp.
//Then,I assigned node-> left to temp. 
//After then,I assigned node -> right instead of node -> left. 
//Finally;I assigned the last temp to node-> right
void swapBinaryTree(struct binaryTreeNode *node){
		
	if (node == NULL)
    	return;
    
    else {
	
	struct binaryTreeNode *temp;
	
	temp= node -> left;
	node -> left = node -> right;
	node -> right = temp;
	
	swapBinaryTree(node->left);
	swapBinaryTree(node->right);
	
	}

} 


int main() {
	
// I set root the binary tree nodes that I specified above
	struct binaryTreeNode *root = generateBinaryTree();
	
	printf(" \n Inorder traversal of binary tree is = \n\n");
// First I printed the inorder form
	findInorder(root);
// Then I applied the swapBinaryTree function
	swapBinaryTree(root);
// Finally, I printed the swap version
	printf(" \n\n After swap Inorder traversal of binary tree= \n\n");
	findInorder(root);
	
    return 0;
}
