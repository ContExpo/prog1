/*
Esercizio 3

Scrivere una funzione che presi in input due vettori con tappo e il nome di un file,
scriva sul file la parte eccedente del vettore più lungo (un elemento per riga).

int vettoriConTappoFile (int A[], int B[], int n, char *nomeFile)

Nel caso che i vettori contengano lo stesso numero di elementi, creare un file vuoto.
Restituire come valore di ritorno il numero di elementi salvati, oppure -1 nel caso di errore di scrittura del file.
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

int vettoriConTappoFile (int v1[], int v2[], char nomeFile[])
{
    int p;
    FILE* fp;
    fp = fopen (nomeFile, "w");

    if (fp == NULL)
        p = -1;

    else
    {
        int i, nv1, nv2, diff;
        nv1 = 0;
        nv2 = 0;
        
        for (i = 0; v1[i] != -1; i++);
        nv1 = i;
        
        for (i = 0; v2[i] != -1; i++);
        nv2 = i;
        
        if (nv1 > nv2)
        {
            for (i = nv2; v1[i] != -1; i++)
                fprintf (fp, "%d\n", v1[i]);
            
            p = nv1 - nv2;
        }
        else
            if (nv2 > nv1)
            {
                for (i = nv1; v2[i] != -1; i++)
                    fprintf (fp, "%d\n", v2[i]);
                
                p = nv2 - nv1;
            }
            else
            {
                p = 0;
            }
            
    fclose (fp);
    }
    
    return p;
}

int main ()
{
    int vett1[DIM], vett2[DIM], differenza;
    char nomefile[31];
    
    srand (time(NULL));
    
    vettoreCasuale (vett1);
    stampaVettore (vett1);
    
    vettoreCasuale (vett2);
    stampaVettore (vett2);
    
    printf ("Digita il nome per il file nel quale salvero' i valori eccedenti del vettore piu' lungo\n(max 30 caratteri): ");
    scanf ("%s", nomefile);
    
    differenza = vettoriConTappoFile (vett1, vett2, nomefile);
    
    if (differenza == -1)
        printf ("ERRORE! Non e' possibile scrivere sul file %s\n", nomefile);
    else
        printf ("La differenza di lunghezza tra i due vettori e' di %d valori\n", differenza);
}
