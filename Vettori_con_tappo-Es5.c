/*
Esercizio 5

Scrivere una funzione che presi in input due vettori con tappo (A, B) metta in un terzo (passato alla funzione vuoto - C) il risultato della concatenazione dei due.

Esempio:

A: [1, 2, 9, 6, 12, -1]
B: [4, 89, 70, -1]
C: [1, 2, 9, 6, 12, 4, 89, 70, -1]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 11

void vettoreCasuale (int v[])
{
    int i, nv;
    nv = ( rand() ) % DIM;
    
    for (i = 0; i < nv; i++)
        v[i] = ( rand() ) % 101;
    
    v[i] = -1;
}

void stampaVettore (int v[])
{
    int i;
    
    for (i = 0; v[i] != -1; i++)
        printf ("Valore in posizione %d del vettore: %d\n", i, v[i]);
    
    printf ("\n");
}

int contaValori (int v[])
{
    int i;
    
    for (i = 0; v[i] != -1; i++);
    
    return i;
}

void concatenaVettori (int v1[], int v2[], int v3[])
{
    int i, j;
    
    for (i = 0; v1[i] != -1; i++)
        v3[i] = v1[i];
    
    j = i;
    
    for (i = 0; v2[i] != -1; i++)
        v3[i + j] = v2[i];
    
    v3[i + j] = -1;
}

int main ()
{
    int vett1[DIM], vett2[DIM], numval1, numval2;
    
    srand (time(NULL));
    
    vettoreCasuale (vett1);
    printf ("Vettore 1:\n");
    stampaVettore (vett1);
    
    vettoreCasuale (vett2);
    printf ("Vettore 2:\n");
    stampaVettore (vett2);
    
    numval1 = contaValori (vett1);
    numval2 = contaValori (vett2);
    
    int vett3[numval1 + numval2 + 1];
    
    concatenaVettori (vett1, vett2, vett3);
    
    printf ("Vettore 3:\n");
    stampaVettore (vett3);
    
    return 0;
}
