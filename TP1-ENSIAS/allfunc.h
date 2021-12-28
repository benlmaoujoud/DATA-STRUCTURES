#include"stdlib.h"
#include "stdio.h"
#include"string.h"

#define ESC 27
#define MAXVILLE 5




// definition of adherent 
typedef struct adherent{
    char code[5];
    char nom[20]; 
    char ville[15]; 
    char domaine[3]; 
    struct adherent *next ;  

}adherent;





typedef struct ville
{
    char nome_Ville[20];  
    adherent *ad ;  

}ville;




adherent *add_adherent(adherent *e  , adherent *liste ); 


void  printList(adherent *liste); 


adherent *delete_adherent(adherent *liste , char* code );



adherent *get_info(); 



void printAll(ville arr[] , int len , char *city) ; 



int search(ville arr[] , int len , char *code); 



//to insert in our linked list : 
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





//print all adherent exist in city 
void print_adh(ville arr[] , int len , char *nom_Ville){
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