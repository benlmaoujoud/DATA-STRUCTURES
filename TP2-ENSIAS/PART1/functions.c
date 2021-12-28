#include "stdio.h"
#include "stdlib.h"
#include "functions.h"


// function 1 :

FILE*  readClient(int numberOfClient , FILE *readFile ){

    Client *clt = (Client*)malloc(sizeof(Client)*numberOfClient); 
    
    unsigned int flag;

    for(int i = 0 ; i<numberOfClient ; i++){
        printf("\t\t\t Informations of Client : %d\n\n",i+1); 
        printf("\t\t\t Name :"); 
        scanf("%s",clt[i].nom);
        printf("\t\t\t Code :"); 
        scanf("%d",&clt[i].code); 
        printf("\t\t\t Solde :"); 
        scanf("%lf",&clt[i].solde);

        flag = fprintf(readFile , " %s %d %lf \n" ,clt[i].nom,clt[i].code,clt[i].solde );
        
        flag > 0 ? printf("\n\t\t\t SUCCESS \n") : printf("\n\t\t\t FAILED OPERATION \n") ; 
 
    }


    return readFile ; 
}


// function 2 : 

void print() {

    FILE *file ;
    
    //Getters : 
    unsigned int code;  
    double solde ; 
    char nom[80]; 

    // we must to use read (r) mode : 
    file = fopen("clients.txt", "r");


    if(!file){
        printf("\t\t\tERROR... : in  print function "); 
        exit(-1); 
    }


    for (int i = 0; i < 3; i++){
        if (fscanf(file,"%s%d%lf",nom,&code,&solde) != EOF){ 
            printf("\t\t\t CLIENT N°%d   : \n\n",i+1); 
            printf("\t\t\t Name : %s \n\n\t\t\t Code : %d \n\n\t\t\t  Solde : %0.2lfDHs \n\n",nom ,code,solde); 
    
        }else{
            printf("\t\t\tError reading Data .\n");
        }
    }
        fclose(file); 
 
    
}


// function 3 : 
void sauvegarder_jeu(char*nom_partie){

    FILE *flot; 
    Joueur *gamer = (Joueur*)malloc(sizeof(Joueur)); 

    if(!(flot = fopen(nom_partie , "wb"))){
        printf("\t\t\tERROR... : in sauvegarder_jeu function  : file can not open  "); 
        exit(-1); 
    }

    printf("\t\t\t Nom Joueur  :"); 
    scanf("%s",gamer->nom);
    do{
        printf("\t\t\t Lieu (must be betw 0 and 50) :"); 
        scanf("%d",&gamer->lieu);

    }while( (gamer->lieu<0) || (gamer->lieu > 50) );
    
    printf("\t\t\t Objects of this Gamer : "); 

    // pour sortir de la boucle j'ai utulisé la var flag , la val de l'objet doit etre egal a  ou 1
    int flag = 1 ; 
    for(int i = 0 ; i < 10 && flag ; i++){
        printf("\t\t\t Object [%d] = ",i+1); 
        scanf("%d",&gamer->objet[i]); 

        if(gamer->objet[i] >1 || gamer->objet[i] == 0 )
            flag = 0 ; 

    }
    

    /* ECRITURE NUMERO DU LIEU */
    fwrite (&gamer->lieu, sizeof(int),1, flot); 

    /* ECRITURE LISTE DES OBJETS */
    fwrite (gamer->objet, sizeof(gamer->objet),1,flot);

    /* FERMETURE FICHIER */
    fclose (flot);
}



void charger_jeu(char *nom_partie) {
    
    
    
    FILE *flot; 

    if(!(flot = fopen(nom_partie , "rb"))){
        printf("\t\t\tERROR... : in sauvegarder_jeu function  : file can not open  "); 
        exit(-1); 
    }
    // Getters : 
    char nom[80]; 
    int lieu ; 
    int objet[10];

    //LECTURE 
    fread(nom , sizeof(nom) , 1 , flot) ; 

    fread(&lieu , sizeof(lieu) , 1 , flot) ; 

    fread(&objet,sizeof(objet),1,flot) ; 

    //fermeture fu fichier :
    fclose(flot); 

    printf("\t\t\t INFOS ABOUT GAMERS : \n") ; 
    printf("\t\t\tNOM : %s",nom); 
    printf("\t\t\tLIEU : %d",lieu); 
    for(int i = 0 ; i<9 ; i++){

        if(objet[i] == 1)
            printf("\t\t\tObjet : Real not img in %d\n\n",i); 
    }
}
