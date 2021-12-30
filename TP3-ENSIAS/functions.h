#include "stdlib.h"



#define   New(tree) (tree*)malloc(sizeof(tree))


// define a tree : 

typedef struct tree {
    
    int key;
    struct tree *left;
    struct tree *right;
}tree;





// add élément in the tree

tree *ajouter(int , tree )  ; 






//explorer the tree in different ways


void preOrder(tree* ) ;

void inOrder(tree* ) ; 

void postOrder(tree* ) ; 


/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
tree* minValueNode(tree* node); 

//delete node from the tree 

tree* deleteNode(tree* root, int key) ; 
