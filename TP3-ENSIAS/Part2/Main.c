#include "stdio.h"
#include "functions.h"
#include "string.h"

/*
AUTHOR : BENLMAOUJOUD MOHAMED
 USAGE  :
         -COMPILE : gcc -o Main.exe Main.c functions.c
         -EXECUTE : ./Main.exe

*/



int main(){

      
    tree *root = NULL;

    char word[80];
    int i =4 ; 
    while(lire_mot(word, 80) != EOF && i-->0)
        root = add(word, root);

    printf("\n\n Traversal in preOrder :  \n");
    preOrder(root); 
    deleteNode(root, "ENSIAS"); 

    printf("\n\n Traversal in preOrder :  \n");
    postOrder(root);
    FILE *file = fopen("test.txt","r"); 
    if(!file)
        printf("\n\n Error ,file can not open\n\n");
    
    flire_mot(file,NULL,80,root);
    printf("\n\n Traversal in preOrder :  \n");
    postOrder(root);
     
      
    return 0 ; 
}