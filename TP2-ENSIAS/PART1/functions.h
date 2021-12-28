// define a client : 
typedef struct Client
{
 unsigned int code ;
    char nom[80]; 
    double solde ; 
}Client;


// define Joueur 
typedef struct Joueur
{
    char nom[80]; 
    int lieu ; 
    int objet[10]; 

}Joueur;



// This function Read all informations about Client

FILE*  readClient(int numberOfClient , FILE *readFile ) ; 


// This function for print info about Client :

void print( ) ; 


/* la fonction sauvegarder_jeu()
 permet de créer,par un programme,un fichier binaire
 pour y sauvegarder les informations du joueur x; 
*/
void sauvegarder_jeu(char*nom_partie);


//Récupérer par programme les informations concernant le joueur à partir du disque : 

void charger_jeu(char *nom_partie) ; 
