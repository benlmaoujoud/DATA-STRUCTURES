#include "stdio.h"
#include "functions.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h> 

tree *add(char *word  , tree *node ){
    
    int flag ; 
    if(node){
        flag = strcmp(word,node->key.word) ; 
        if(flag<0)
            node->left = add(word,node->left); 

        else if(flag>0)
            node->right= add(word,node->right); 

        else //both equale 
            node->key.freq++ ; 
    }else{


        node = New(tree) ; 
        strcpy(node->key.word,word); 
        node->left =  NULL ; 
        node->right = NULL;
    }

    return node; 

}




void preOrder(tree *node)
{
     if(node)
     {
        printf("Word : %s\t Frequence ; %d\n",node->key.word,node->key.freq);
        preOrder(node->left);
        preOrder(node->right);
     }
}



void postOrder(tree *node)
{
     if(node)
     {
        postOrder(node->left);
        postOrder(node->right);
        printf("Word : %s\t Frequence ; %d\n",node->key.word,node->key.freq);

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



tree* deleteNode(tree* root, char* key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (strcmp(key ,root->key.word)<0)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (strcmp(key ,root->key.word)>0)
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
        root->right = deleteNode(root->right, temp->key.word);
    }
    return root;
}


int lire_mot(char *mot, int maxm)
{
    char c;
    char *m=mot;
    while( !isalpha(c=getchar()) && (c!= EOF) )
           ;
    if(c == EOF)
         return EOF;
    *m=c; m++;
    for( ; isalnum( c=getchar() ) && (--maxm>0) ; )
    {
         *m=c;
         m++;
    }
    *m ='\0';
    return c;
}



int flire_mot(FILE *f, char *mot, int maxm , tree *root){

    unsigned int numberOfWord = 0 ; 
    char *tmp = (char*)malloc(sizeof(maxm));
  
    while (!feof(f)){
        
        fgets(tmp,maxm,f);
        root = add(tmp,root); 

    numberOfWord++; 
    }
        
  
    return numberOfWord;   
}