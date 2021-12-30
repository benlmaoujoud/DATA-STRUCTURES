#include "stdio.h"
#include "functions.h"



tree *add(int item, tree *node){

    int flag ; 
    if(node){
        
    if(item < node->key ) 
        node->left = add(item,node->left); 
    else 
        node->right = add(item,node->right);
    
    }
     

    else{
        node = New(tree);
        node->key= item ; 
        node->right = NULL; 
        node->left = NULL; 
    }

return node ; 

}



void inOrder(tree *tree ) {
    if(tree){
        inOrder(tree->left);
        printf("\t\t\t Key : %d\n",tree->key); 
        inOrder(tree->right); 
    }
}

void preOrder(tree *tree ) {
    if(tree != NULL){
        printf("\t\t\t Key : %d\n",tree->key); 
        preOrder(tree->left);
        preOrder(tree->right); 
    }
}


void postOrder(tree *tree ) {
    if(tree){
        postOrder(tree->left);
        postOrder(tree->right);
        printf("\t\t\t Key : %d\n",tree->key); 
 
    }
}




tree* minValueNode(tree* node)
{
    tree*current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}



// delete a node from tree : 

tree* deleteNode(tree* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {

        // node has no child
        if (root->left==NULL && root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            tree* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        tree* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
