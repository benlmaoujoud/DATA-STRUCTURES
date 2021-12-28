
#include"stdio.h"
#include"functions.h"
#include"string.h"
#include"stdlib.h"



adherent *add_adherent(adherent *e  , adherent *liste ){
     adherent *p; 

     if(!liste){
         liste = e ; 
     }else 
     {
         p = liste ; 
         while(p->next)
             p = p->next ; 
         p->next = e ;

     }

 return liste; 
 }



 //print all adherent in our list 
 void  printList(adherent *liste){

     adherent *p = liste;
     unsigned int i = 0; 
     if (!p)
     {
         printf("\n\n\t\t\t\tYOUR ADHERENTS IS EMPTY TRY TO ADD SOME ADHRENTS\n\n\n"); 
         return ; 
     }

     while(p){ 
         printf("\t\t\t\t-------------Les Informations de L'adherent Numero°%d------------\n\n",i++); 
         printf("\t\t\t\t\tCode : %s \t  Full Name : %s \n\t\t\t\t\tCity : %s \t  domaine : %s\n",p->code,p->nom,p->ville,p->domaine);
         p = p->next;
     }

 }



 // delete adherent  by code 

 adherent *delete_adherent(adherent *liste , char* code ){
     adherent *p =liste;
     adherent *tmp = NULL; 
     unsigned int pos = 0 ; 
     while (strcmp(p->code,code) && p->next){
         p =p->next;
         pos++; 
     }
     if(!p->next){ // if p.next is null 
         printf("\n\n\t\t\t\t-----------Sorry this adhrent not exist-----------\n\n");
         return NULL; 
     }
     else{
         p = liste; 
         for(int i = 0 ; i<pos-1 ; i++)
             p = p->next;
         tmp = p->next ; 
         p->next = tmp->next ; 
         free(tmp);  
     }
     return liste; 

 }





 //get infos 
 adherent* get_info(){
     adherent *e = (adherent*)malloc(sizeof(adherent)); 
     printf("\t\t\t\tCode of this new Adherent :  "); 
     scanf("%s",e->code); 
     printf("\t\t\t\tFull Name of this new Adherent :  "); 
     scanf("%s",e->nom); 
     printf("\t\t\t\tCity of living of this new Adherent :  "); 
     scanf("%s",e->ville); 
     printf("\t\t\t\tDomaine of this new Adherent :  "); 
     scanf("%s",e->domaine); 
     e->next = NULL; 

     return e ; 
 }





 void printAdherentInCIty(ville arr[] , int len , char *nom_Ville){
     adherent *p; 
     unsigned int count = 0; 
     unsigned int i = 0; 
     while (i<len)
     {
         if(strcmp(arr[i].nome_Ville , nom_Ville) == 0)
         {
             p =(adherent*)arr[i].ad;
             printf("\t\t\t\t\tCode : %s \t  Full Name : %s \t  domaine : %s\n\n",p->code,p->nom,p->domaine);
             count++; 
         }


     i++; 
     }
     printf("\t\t\t\t\t Number of adherent in %s : %d \n",nom_Ville,count); 

 }




 // search for adherent by code 
 int search(ville arr[] , int len , char *code){
     unsigned int  flag = 0 ;
     unsigned int i = 0 ; 
     while(!flag && i<len){
         if(!strcmp(arr[i].ad->code , code))
             flag = 1 ; 
     i++; 
     }

     return flag ; 
 }





 adherent* charger(){


    FILE *adhrents = fopen("adher.dta","rb+");
    adherent *head = NULL ; 
    adherent *last = NULL ;
    
 	if(adhrents == NULL){
 		printf("\t\t\t Erreur d'ouverture du fichier !\n");
 		exit(-1);
 	}
     // getter 
    adherent *e = (adherent*)malloc(sizeof(adherent)); 

        while(fread(e,sizeof(adherent),1,adhrents) == 1)
        {
            if(head == NULL){
                head = last = (adherent*)malloc(sizeof(adherent)); 
            }else{
                last->next =(adherent*)malloc(sizeof(adherent));  
                last = last->next; 
            }

        strcpy(last->code,e->code);      
        strcpy(last->nom,e->nom); 
        strcpy(last->ville,e->ville); 
        strcpy(last->domaine,e->domaine); 

        last->next = NULL ; 
        } 

 	fclose(adhrents);

    return head ; 
 }

 void save(adherent *adherents){

     // mode append a in binary :
     FILE *file = fopen("adher.dta","ab");

 	if(file == NULL){
 		printf("\t\t\t Erreur d'ouverture du fichier !\n");
 		exit(-1);
 	}

     adherent *curr = adherents ;

     while(curr){
         if(fwrite(curr,sizeof(adherent),1,file) !=1 ){
 		    printf("\n Erreur d'ecriture' !");
 		    exit(-1);
         }
     curr = curr->next; 
     }
     fclose(file);  

 } 