#include <stdio.h>
#include "functions.c"

int main(){

    int arr[]={55,34,49,20,38,58,10,50,25,22,24};

    tree *BST = NULL;
        for(int i=0;i<11;i++)
            BST = add(arr[i], BST);
    
    printf("\t\t\tInorder traversal of the given tree : \n\n");
    inOrder(BST);
    printf("\t\t\tPostorder traversal of the given tree : \n\n");
    postOrder(BST); 
 
    printf("\t\t\t Delete 20\n");

    deleteNode(BST,20);
    printf("\t\t\t Delete 55\n");

    deleteNode(BST,55);  
    printf("\t\t\tPreOrder traversal of the given tree : \n\n");
    preOrder(BST); 


    return 0; 
}
