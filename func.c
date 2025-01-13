#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "typeDef.h"


void add_elem(Libro *elem, ReadPtr dati){    

    Libro newPtr = malloc(sizeof(Libro));       

    if (newPtr != NULL) {   

        newPtr->autore = malloc(strlen(dati.autore));   

        strcpy(newPtr->autore, dati.autore);
        
        newPtr->titolo = malloc(strlen(dati.titolo));  
         
        strcpy(newPtr->titolo, dati.titolo);
        
        newPtr->prezzo = dati.prezzo;       

        newPtr->next = *elem;

        *elem = newPtr;

    }
    else{

      printf("\n not inserted. No memory available.\n");

   };

}

void del(Libro *elem, char *inf){

    if (strcmp((*elem)->titolo , inf ) == 0) { 

      Libro tempPtr = *elem; 

      *elem = (*elem)->next; 

      free(tempPtr); 
      
   } 
   else { 
      Libro prev = *elem;

      Libro curr = (*elem)->next;

      while (curr != NULL && (strcmp(curr->titolo, inf) != 0)) { 

         prev = curr; 
         curr = curr->next; 

      } 

      if (curr != NULL) { 

         Libro tempPtr = curr;

         prev->next = curr->next;

         free(tempPtr);
         
      } 

   }   

};

void modify(Libro *elem, char *inf,ReadPtr dati){

    if (strcmp((*elem)->titolo , inf ) == 0) { 

        (*elem)->autore = malloc(strlen(dati.autore));           
        
        strcpy((*elem)->autore, dati.autore);

        (*elem)->titolo = malloc(strlen(dati.titolo));        
         
        strcpy((*elem)->titolo, dati.titolo);
        
        (*elem)->prezzo = dati.prezzo;            
      
   } else { 

      Libro prev = *elem;

      Libro curr = (*elem)->next;

      // loop to find the correct location in the list
      while (curr != NULL && (strcmp(curr->titolo, inf) != 0)) { 

         prev = curr; 
         curr = curr->next;  

      } 

      if (curr != NULL) { 

        curr->autore = malloc(strlen(dati.autore));           
        
        strcpy(curr->autore, dati.autore);

        curr->titolo = malloc(strlen(dati.titolo));        
         
        strcpy(curr->titolo, dati.titolo);
        
        curr->prezzo = dati.prezzo;      
         
      } 

   }   

};

void printPtr(Libro *elem){

    Libro tmp = *elem;

     while(tmp != NULL){
        
        printf("\n%s %s %.2f\n",tmp->titolo ,tmp->autore, tmp->prezzo);
        
        tmp = tmp->next;
        
    };  

}

void writeFile(Libro *elem){
    
    ReadPtr tmp;

    tmp.autore[0] = '\0';
    tmp.titolo[0] = '\0';
    tmp.prezzo = 0.0;

    Libro tmpLst = *elem;   

     FILE *fp;    

    fp=fopen("gest.bin", "rb+");


    if(fp==NULL){

        printf("non c'è");
        fp = fopen("gest.bin", "w");

        if(fp!=NULL){

            printf("file creato");
            fp=fopen("gest.bin", "rb+");

        }else{

            printf("non è stato possibile creare il file");

        }

    }


    printf("\n\n");

    int x = 0;

    while( tmpLst != NULL ){
    
        strcpy(tmp.autore,tmpLst->autore);
    
        strcpy(tmp.titolo,tmpLst->titolo);

        tmp.prezzo = tmpLst->prezzo;

       x++;

       fseek(fp, x * sizeof(ReadPtr), SEEK_SET);
       
       fwrite(&tmp, sizeof(ReadPtr), 1, fp);

       printf("\ntitolo: %s autore:%s prezzo: %.2f scritto su file",tmp.titolo,tmp.autore,tmp.prezzo);

       tmpLst = tmpLst->next;

    }

    fclose(fp);

}
    

void readFile(Libro *libroPtr){  

    ReadPtr tmp;  

    FILE *fp;    

    fp=fopen("gest.bin", "rb");    

    int x = 0;

    printf("\n\n");

    if(fp!=NULL){

     while (!feof(fp)) {

         x++;
        
        fseek(fp, (x) * sizeof(ReadPtr), SEEK_SET);          

        fread(&tmp, sizeof(ReadPtr), 1, fp);      

        if(!feof(fp)){

            printf("letto %s %s %.2f \n", tmp.titolo,tmp.autore,tmp.prezzo);


            add_elem(libroPtr,tmp);
        }

     }    

    }else{

        printf("File inesistente");

    }

     
     fclose(fp);

}

void resetFile(){

    ReadPtr tmp;

    tmp.autore[0] = '\0';
    tmp.titolo[0] = '\0';
    tmp.prezzo = 0.0;
 

     FILE *fp;    

    fp=fopen("gest.bin", "w");
    
    fwrite(&tmp, sizeof(ReadPtr), 1, fp);

    fclose(fp);   

}

void banner(){

    printf("\x1b[32m");
    printf("\n                            ####      #####    ####    #######    #     ####    #     #       #      #       #####       ");                                     
    printf("\n                           #         #        #    #      #       #    #    #   # #   #      # #     #      #            ");
    printf("\n                          #          #####      #         #       #    #    #   #  #  #     #   #    #      ######       ");
    printf("\n                          #   ####   #           #        #       #    #    #   #   # #    #######   #      #            ");
    printf("\n                           #    #    #        #    #      #       #    #    #   #     #   #       #  #      #            ");
    printf("\n                            ####      #####    ####       #       #     ####    #     #   #       #  ####    #####       ");
    printf("\n\n\n\n\n");

}

void menu(){

    printf("\n1) aggiungi elemento:");
    printf("\n2) visualizza lista:");
    printf("\n3) cancella elemento:");
    printf("\n4) salva lista:");
    printf("\n5) leggi file:");
    printf("\n6) modifica elemento:");
    printf("\n0) esci \n");
    
}



