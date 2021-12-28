#include "stdio.h"
#include "stdlib.h"


typedef struct tree{

    int key ; 
    struct tree *left ;
    struct tree *right; 
}tree; 

// this function transform an #ARRAY to a #BINARY-SEARCH TREE : 

tree *arrTotree(int *arr , int size , int start  , int end  );

//THE IDEA  :  
/*
if we want to transform our array to BST (binary search tree) we have to follow this steps 

step 1 : make sure that our arrayy is sorted 

step 2 : get the midd of this array and puted as a root ouf the tree 

step 3 : left of the tree must have all elment in the range  0 to mid-1
         right :from  mid to length -1 
step 4 : make it recursivly 

example :  
        t[]={55,11,44,33,22};
    
    1 - sort : t[]={11,22,33,44,55}
    2 - left :[11,22] ,mid = 33 right [44,55] : 
    3 rec1:        /33\
                /      \
        [11,22]         [44,55]
     
      rec2:        /33\
                 /      \
                22      44
               /          \
             11            55


*/   
//  Insert a node in a binary search tree : 

tree *addTotree(int item , tree * root) ; 


// Traversal (explore) in inOroder 

void printInOrder(tree *root); 


// Delete in item from a tree : 

void deleteItm(int key , tree *root) ; 



// let's implement thos functions 


tree *arrTotree(int *arr , int size , int start  , int end  ){
    

    qsort(arr , size , sizeof(*arr) , comp) ; 
    
    
    // base : 
    if(start > end)
        return NULL ; 

    int mid = ( start + end )/2 ; 

    tree *node = (tree*)malloc(sizeof(tree)) ; 
    node->key = arr[mid] ; 
    node->left = arrTotree(arr,size,start , mid-1) ; 
    node->right= arrTotree(arr, size , mid , end); 

    return node ;
}
/*
this one we need it for sorting our array  by qsort() function
*/
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
