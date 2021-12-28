
 /*
 AUTHOR : BENLMAOUJOUD MOHAMED
 USAGE  :
         -COMPILE : gcc -o Test.exe Test.c functions.c
         -EXECUTE : ./Test.exe
 */

 #include "stdio.h"
 #include "functions.h"
 #include "string.h"
 #include"stdlib.h"

 // global variable  

 unsigned int i = 0 ; 

 int main()
 {

     adherent *adherents = charger() ;
     char *choice =(char*)malloc(sizeof(char)); 


     ville  all_data[MAXVILLE]; 
     char *city = malloc(20); 
     unsigned int option , flag;
     char *code = (char*)malloc(20);  
     adherent *rest = NULL ; 
     adherent *e; 

     do
     {
             printf("\n\t\t#####################################\n\n"); 
             printf("\t\t\t *****MENU******\n\n");
             printf("\t\t\t 1. ADD ADHERENT\n");
             printf("\t\t\t 2. DELETE ADHERENT \n");
             printf("\t\t\t 3. PRINT ADHERENTS \n");
             printf("\t\t\t 4. SEARCHE FOR ADHERENT: \n");
             printf("\t\t\t 5. PRINT ADHERENT BY CITY: \n");

             printf("\t\t\t 6. EXIT\n\n");
             printf("\t\t\t ***************\n\n");
             printf("\t\t\t Enter your choice : ");
             scanf("%d",&option);

                 switch (option)
                 {
                          case 1:
                                 e = (adherent*)get_info(); 
                                 adherents = add_adherent(adherents,e);
                                 printf("\t\t\t\tName of the File Please  :"); 
                                 all_data[i].ad = e ; 
                                 strcpy(all_data[i].nome_Ville , e->ville); 
                                 printf("\n\n\t\t\t\t-----SUCCESFULL OPARTION--------\n\n");
                                 i++; 
                                 break;

                         case 2 : 
                                 if(adherents){
                                         printf("\t\t\t\tCode of adherent to delete it :"); 

                                         scanf("%s",code); 
                                         adherent *rest = delete_adherent(adherents,code); 
                                         if(rest)
                                                 adherents = rest ;
                                         else
                                                 printf("\n\n\t\t\t\t This Adhrent is not exist \n");  
                                 }else
                                         printf("\n\n\t\t\t\tYou can not delete from an Empty List\n\n"); 

                         break; 

                         case 3 : 
                                 printList(adherents);

                         break; 

                         case 4 : 
                                 if(adherents){
                                         printf("\t\t\t\tEnter the ID of the desired Adherent :"); 
                                         scanf("%s",code); 
                                         flag = search(all_data,i,code); 
                                         flag == 1 ? printf ("\n\n\t\t\t\t-----This adherent Exist :)-----\n\n") : printf("\n\n\t\t\t\t-----------Sorry this Adherent is not Exist ):-----------\n\n"); 

                                 }else
                                         printf("\n\n\t\t\t\tYou can not search in Empty List\n\n"); 
                         break;

                         case 5 : 
                                 printf("\n\n\t\t\t Enter the City you want  : "); 
                                 scanf("%s",city); 
                                 printAdherentInCIty(all_data,i,city); 

                         break; 

                         case 6 :
                                 printf("\n\n\t\t\t GOOD BY :)\n "); 

                                 break; 
                         default:
                                 printf("\t\t\tYOU DON'T CHOES ANYTHING FROM THE MENU... TRY AGAIN \n"); 
                         break;
                 }   

     }while(option != 6);


     printf("\t\t\t YOU WANT TO SAVE THE FILE (YES / NO ) : "); 

     scanf("%s",choice); 
     if(strcmp(choice,"YES") == 0 || strcmp(choice,"Y") == 0 || strcmp(choice,"y") == 0 || strcmp(choice,"yes") == 0) 
        save(adherents);


     return 0 ; 
 }