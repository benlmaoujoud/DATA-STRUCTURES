#include "stdio.h"


 #define ESC 27
 #define MAXVILLE 5




 // define adherent 
 typedef struct adherent{
     char code[5];
     char nom[20]; 
     char ville[15]; 
     char domaine[3]; 
     struct adherent *next ;  

 }adherent;



 //define city , city have adherents 

 typedef struct ville
 {
     char nome_Ville[20];  
     adherent *ad ;  

 }ville;



 //to insert in our linked list : 

 adherent *add_adherent(adherent *e  , adherent *liste ); 




 //print all adherent in our list 

 void  printList(adherent *liste); 





 // delete adherent  by code 

 adherent *delete_adherent(adherent *liste , char* code );




 //get infos 

 adherent *get_info(); 





 //print all adherent exist in city 

 void printAll(ville arr[] , int len , char *city) ; 






 // search for adherent by code 

 int search(ville arr[] , int len , char *code); 



 //print all adherent exist in city 

 void printAdherentInCIty(ville arr[] , int len , char *nom_Ville);


 // charger les infos sur la memoire
 adherent* charger();

 // save adherents in dd
 void save(adherent * adherents); 