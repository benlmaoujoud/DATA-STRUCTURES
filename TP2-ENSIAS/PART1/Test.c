#include "stdio.h"
#include "stdlib.h"
#include "functions.h"

/*

Usage :
compile : gcc -o Test.exe Test.c functions.c 
exe : ./Test.c

*/

// main function 

int main(){

    int option ; 
    char *nameOfGame = (malloc(30)); 
    FILE *allClients ; 
    unsigned int numberOfClients  = 2 ; 

        do
        {
            printf("\n\t\t#####################################\n\n"); 
            printf("\t\t\t *****MENU******\n\n");
            printf("\t\t\t 1. ADD CLIENT INFO TO FILE \n");
            printf("\t\t\t 2. PRINT DATA OF A CLIENT  \n");
            printf("\t\t\t 3. SAVE THE GAME  \n");
            printf("\t\t\t 4. CHARGER LE JEU  \n");

            printf("\t\t\t 5.EXIT  \n");


            printf("\t\t\t ***************\n\n");
            printf("\t\t\t Enter your choice : ");
            scanf("%d",&option);

                switch (option)
                {
                        case 1:
                                if(!(allClients = fopen( "clients.txt", "w+" ))){

                                    printf("ERROR... : Can not open the file "); 
                                    exit(-1); 
                                }else   
                                       allClients = readClient(numberOfClients , allClients); 
                        
                                fclose(allClients); 
                                       
                                break;

                        case 2 : 
                                print();
                        
                                break; 
                        case 3 :
                                printf("\t\t\t GAME SHOULD BE NAMED TO SAVE IT , PLEASE ENTER HT NAME : "); 
                                scanf("%s",nameOfGame); 
                                sauvegarder_jeu(nameOfGame); 

                                break;
                     
 
                        case 4 : 
                                printf("\t\t\tPLEASE ENTER THT NAME : "); 
                                scanf("%s",nameOfGame); 
                                charger_jeu(nameOfGame);
                                break;
                        case 5 : 
                                printf("\t\t\tGOOD BY : "); 
                                break;   
                        default:
                                printf("\t\t\tYOU DON'T CHOES ANYTHING FROM THE MENU... TRY AGAIN \n"); 
                        break;
                }   

    }while(option != 5);

return 0; 
}

// end main 
