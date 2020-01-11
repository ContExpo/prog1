/*
Esercizio 6

Scrivere una funzione che preso in input un vettore con tappo, restituisca
in una variabile passata per riferimento che rappresenta il numero di volte
che il valore massimo nel vettore tappo si presenta.
Restituire -1 se il vettore con tappo è vuoto.
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
}

int calcoloValMax (int v[])
{
    int i, max;
    
    max = v[0];
    
    if (max != -1)
        for (i = 1; v[i] != -1; i++)
            if (max < v[i])
                max = v[i];
            
    return max;
}

void contaOccorrenze (int v[], int n, int* occ)
{
    int i;
    
    *occ = 0;
    
    if (v[0] == -1)
        *occ = -1;
    else
        for (i = 0; v[i] != -1; i++)
            if (v[i] == n)
                (*occ)++;
}

int main ()
{
    int vett[DIM], valmax, numocc;
    
    srand (time(NULL));
    
    vettoreCasuale (vett);
    printf ("Vettore:\n");
    stampaVettore (vett);
    
    valmax = calcoloValMax (vett);
    
    contaOccorrenze (vett, valmax, &numocc);
    
    if (numocc == -1)
        printf ("Il vettore e' vuoto\n");
    else
    {
        printf ("Il valore massimo contenuto nel vettore e' %d\n", valmax);
        
        if (numocc == 1)
            printf ("Il valore massimo %d ricorre %d volta\n", valmax, numocc);
        else
            printf ("Il valore massimo %d ricorre %d volte\n", valmax, numocc);
    }
    
    return 0;
}
