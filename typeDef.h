

#ifndef TYPEDEF_H

#define TYPEDEF_H


#define MAX_VAL 50

struct Elem{

    char *titolo;
    char *autore;
    float prezzo;
    struct Elem *next;

};

struct Read{

    char titolo[MAX_VAL];
    char autore[MAX_VAL];
    float prezzo;
    

};

typedef struct Read ReadPtr;

typedef struct Elem *Libro;

#endif