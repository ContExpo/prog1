/* Esercizio 1

Caricamento dei valori in un vettore con tappo e stampa attraverso funzioni con passaggio dei dati per valore.

*/

#include <stdio.h>
#define DIM 11
void caricaVettore (int v[])
{
    int i;
    i = 0;
    
    printf ("Digita una serie di valori interi e positivi\n");
    do
    {
        do
        {
            printf ("Digita il valore in posizione %d, -1 per terminare: ", i);
            scanf ("%d", &v[i]);
            
            if (v[i] < 0 && v[i] != -1)
                printf ("Solo valori positivi!\n");
        }
        while (v[i] < 0 && v[i] != -1);
        
        i++;
    }
    while (i < (DIM - 1) && v[i -1] != -1);
    
    v[i] = -1;
}

void stampaVettore (int v[])
{
    int i;
    
    for (i = 0; v[i] != -1; i++)
        printf ("Valore in posizione %d del vettore: %d\n", i, v[i]);
    
    printf ("\n");
}

int main ()
{
    int vett[DIM];
    
    caricaVettore (vett);
    
    stampaVettore (vett);
    
    return 0;
}
