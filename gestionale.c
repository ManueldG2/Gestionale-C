#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>


//TODO stampa elemento selezionato ( cerca per titolo - autore  ) 
//TODO aggiungere id 
//TODO migliorare gestione file

int main(){

    Libro libroPtr = NULL; 

    ReadPtr dati;

    int choice = 0;

    system("cls");

    banner();

    while(choice!=-1){

        printf("\x1b[32m");

        menu();

        printf("\x1b[0m \n");
        printf("\n\x1b[31mscelta: ");

        scanf("%d",&choice);
        system("cls");
        
        if(choice==1){

            printf("prezzo: ");
            scanf("%f",&dati.prezzo);
        
            printf("titolo: ");
            scanf("%s",dati.titolo);            

            printf("autore: ");
            scanf("%s",dati.autore);                   
            
            add_elem(&libroPtr,dati);  

       

        }else if(choice==2){

            printPtr(&libroPtr);
            printf("\n");
            system("pause");

        }else if(choice==3){

            printf("Elemento da cancellare: ");
            scanf("%s",dati.titolo);
            del(&libroPtr,dati.titolo);  

        }else if(choice==4){

            resetFile();
            writeFile(&libroPtr);
            
            
        }else if(choice==5){
            
             readFile(&libroPtr);
             printf("\n");
             system("pause");
            
        }else if(choice==6){

            char inf[30];
            
            printf("titolo da modificare: ");
            scanf("%s",inf); 

            printf("prezzo: ");
            scanf("%f",&dati.prezzo);

            printf("titolo: ");
            scanf("%s",dati.titolo);            

            printf("autore: ");
            scanf("%s",dati.autore);  

            modify(&libroPtr,inf,dati);

            printf("\n");

            system("pause");

        }       
        else if(choice == 0){

            choice = -1;

        }     

         system("cls"); 

    }
    printf("\x1b[0m");
    return 0;

};