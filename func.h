#include <stdio.h>
#include"typeDef.h"

#ifndef FUNC_H

#define FUNC_H

extern void add_elem(Libro *, ReadPtr);
extern void printPtr(Libro *); 
void del(Libro *, char *);

void modify(Libro *, char *, ReadPtr);

void writeFile(Libro *);
void readFile();

void resetFile();

void banner();

void menu();

#endif