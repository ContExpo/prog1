/*
Esercizio 4

Scrivere una funzione che preso in input un vettore con tappo, restuisca all’esterno
quanti sono i valori positivi, i valori negativi e i valori nulli.

NOTA: Io eseguo l'esercizio come richiesto, ma per definizione un vettore con tappo
           puo' contenere solo valori postivi o nulli, quindi il contatore per i valori negativi
           non ha molto senso.
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

void contaPosNegNul (int v[], int* pos, int* neg, int* nul)
{
    int i;
    *pos = 0;
    *neg = 0;
    *nul = 0;
    
    for (i = 0; i < DIM-1 && v[i] != -1; i++)
        if (v[i] > 0)
            (*pos)++;
        else
            if (v[i] < 0)
                (*neg)++;
                else
                    (*nul)++;
}

int main ()
{
    int vett[DIM], valpos, valneg, valnul;
    
    srand (time(NULL));
    
    vettoreCasuale (vett);
    stampaVettore (vett);
    
    contaPosNegNul (vett, &valpos, &valneg, &valnul);
    
    printf ("Il vettore contiene %d valori positivi, %d valori negativi e %d valori nulli\n", valpos, valneg, valnul);
    
    return 0;
}
