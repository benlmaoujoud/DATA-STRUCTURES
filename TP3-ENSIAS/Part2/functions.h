

//to create a node 
#define New(tree) (tree*)malloc(sizeof(tree))


// define data : 
typedef struct data {
    int freq  ; 
    char word[80]; 

}data;




// define a tree :
typedef struct tree {

    struct data key ; 
    struct tree *left , *right ; 
}tree ; 



// add élément in the tree

tree *add(char* , tree* )  ; 






//explorer the tree in different ways


void preOrder(tree* ) ;

void inOrder(tree* ) ; 

void postOrder(tree* ) ; 




/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
tree* minValueNode(tree* node); 






//delete node from the tree 

tree* deleteNode(tree* root, char* key) ; 


int lire_mot(char *mot, int maxm) ; 



//lire les mots à partir d’un fichier texte
int flire_mot(FILE *f, char *mot, int maxm ,tree *root ); 